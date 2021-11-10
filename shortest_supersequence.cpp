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

    int t[n+1][m+1]; 

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 or j==0){
                t[i][j] =  0 ; 
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                t[i][j] = 1 + t[i-1][j-1]; 
            }

            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]); 
            }
        }
    }

    int lcs = t[n][m];

    int super_sequnce = n+m-lcs ;

    cout<<super_sequnce<<endl; 

}