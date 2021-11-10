#include<bits/stdc++.h>
using namespace std;

int static t[1001][1001];

int floor(int e,int f){
    if(f==0 or f==1){
        return f; 
    }

    if(e==1){
        return f; 
    }

    if(t[e][f] != -1){
        return t[e][f]; 
    }

    int mini = INT_MAX; 
    int low = 0;
    int high = 0; 

    for(int k=1;k<=f;k++){
        if(t[e-1][k-1] != -1){
            low = t[e-1][k-1]; 
        }

        else{
            low = floor(e-1,k-1); 
        }

        if(t[e][f-k] != -1){
            high = t[e][f-k]; 
        }

        else{
            high = floor(e,f-k); 
        }

        int temp = 1 + max(low,high); 

        mini = min(mini,temp); 
    }

    return t[e][f] = mini ; 
}

int main(){
    int e,f;
    cin>>e>>f;

    memset(t,-1,sizeof(t)); 

    cout<<floor(e,f)<<endl; 
}