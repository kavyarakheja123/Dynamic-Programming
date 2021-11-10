#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n]; 

    for(int i=0;i<n;i++){
        cin>>arr[i]; 
    }

    int sum = accumulate(arr,arr+n,0); 

    if(sum %2 != 0){
        cout<<"0"<<endl; 
        return 0; 
    }

    int target = sum/2;

    bool t[n+1][target+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<target+1;j++){
            if(i==0){
                t[i][j] = false ; 
            }

            if(j==0){
                t[i][j] = true ; 
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] or t[i-1][j] ; 
            }

            else{
                t[i][j] = t[i-1][j]; 
            }
        }
    }

    cout<<t[n][target]<<endl; 
}