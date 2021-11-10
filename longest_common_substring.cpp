#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    string x;
    cin>>x;

    int m;
    cin>>m;

    string y;
    cin>>y;

    int t[101][101];
    int res = INT_MIN; 

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 or j==0){
                t[i][j] = 0; 
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                t[i][j] = 1 + t[i-1][j-1]; 
                res = max(res,t[i][j]); 
            }

            else{
                t[i][j] = 0; 
            }
        }
    }

    cout<<res<<endl; 
}