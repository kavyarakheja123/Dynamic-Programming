#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    int arr[n]; 

    for(int i=0;i<n;i++){
        cin>>arr[i]; 
    }

    int t[n+1][k+1];
    memset(t,0,sizeof(t)); 

    for(int i=1;i<n+1;i++){
        for(int j=1;j<k+1;j++){
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j/arr[i-1]] + t[i-1][j] + 1; 
            }

            else{
                t[i][j] = t[i-1][j]; 
            }
        }
    }

    cout<<t[n][k]<<endl; 
}