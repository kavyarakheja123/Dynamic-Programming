/* CODE FOR ROD CUTTING PROBLEM IS SAME AS UNBOUNDED KNAPSACK */ 

#include<bits/stdc++.h>
using namespace std;

int static t[101][1001]; 

void unbounded_knapsack(int wt[],int val[],int n,int w){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0 or j==0){
                t[i][j] = 0 ; 
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                int ans1 = val[i-1] + t[i][j-wt[i-1]]; 
                int ans2 = t[i-1][j]; 

                t[i][j] = max(ans1,ans2); 
            }

            else{
                t[i][j] = t[i-1][j]; 
            }
        }
    }
}

int main(){
    int n;
    cin>>n;

    int wt[n];
    int val[n]; 

    for(int i=0;i<n;i++){
        cin>>wt[i]; 
    }

    for(int i=0;i<n;i++){
        cin>>val[i]; 
    }

    int w;
    cin>>w;

    memset(t,-1,sizeof(t)); 

    unbounded_knapsack(wt,val,n,w); 

    cout<<t[n][w]<<endl; 
}