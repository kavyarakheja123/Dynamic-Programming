#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int sum;
    cin>>sum; 

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bool t[n+1][sum+1]; 

    for(int i=0;i<n+1;i++){  //INITIALIZATION :- SAME AS BASE CASE IN RECURSIVE FUNCTION :) 
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j] = false ; 
            }

            if(j==0){
                t[i][j] = true ; 
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] or t[i-1][j]; 
            }

            else{
                t[i][j] = t[i-1][j];  
            }
        }
    }

    cout<<t[n][sum]<<endl; 
}