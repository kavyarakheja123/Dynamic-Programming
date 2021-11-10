#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,r;
    cin>>n>>r;

    int t[n+1][r+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<r+1;j++){
            if(i==0){
                t[i][j] = 0; 
            }

            if(j==0){
                t[i][j] = 1; 
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<r+1;j++){
            t[i][j] = t[i-1][j] + j*t[i-1][j-1]; 
        }
    }

    cout<<t[n][r]<<endl; 
}