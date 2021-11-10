#include<bits/stdc++.h>
using namespace std;

int t[1001]; 

int solve(int n,int arr[]){
    if(n>=1){
        t[0] = arr[0];
    }

    if(n>=2){
        t[1] = arr[0] + arr[1]; 
    }

    if(n>2){
        t[2] = max((arr[0]+arr[1]),max((arr[1]+arr[2]),(arr[0]+arr[2]))); 
    }

    if(t[n] != -1){
        return t[n]; 
    }
    

    for(int i=3;i<n;i++){
        int ans1 = t[i-1];
        int ans2 = t[i-2] + arr[i];
        int ans3 = t[i-3] + arr[i-1] + arr[i];
        
        t[i] = max(max(ans1,ans2),ans3); 
    }

    return t[n-1];    
}

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i]; 
    }

    memset(t,-1,sizeof(t)); 

    cout<<solve(n,arr); 
}