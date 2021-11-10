#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[],int val[],int w,int n){
    if(n==0 or w==0){
        return 0; 
    }

    if(wt[n-1]<=w){
        int ans1 = val[n-1] + knapsack(wt,val,w-wt[n-1],n-1);
        int ans2 = knapsack(wt,val,w,n-1); 

        return max(ans1,ans2);  
    }

    else{
        return knapsack(wt,val,w,n-1); 
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

    cout<<knapsack(wt,val,w,n)<<endl; 
}