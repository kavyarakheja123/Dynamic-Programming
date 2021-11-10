#include<bits/stdc++.h>
using namespace std;

int static t[101][1001]; 

int knapsack(int wt[],int val[],int w,int n){
    if(n==0 or w==0){
        return 0 ; 
    }

    if(t[w][n] != -1){
        return t[w][n]; 
    }

    if(wt[n-1]<=w){
        int ans1 = val[n-1] + knapsack(wt,val,w-wt[n-1],n-1); 
        int ans2 = knapsack(wt,val,w,n-1); 

        return t[w][n] = max(ans1,ans2); 
    }

    else{
        return t[w][n] = knapsack(wt,val,w,n-1); 
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

    cout<<knapsack(wt,val,w,n)<<endl; 
}