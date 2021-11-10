#include<bits/stdc++.h>
using namespace std;

int main(){
    int p,q,r;
    cin>>p>>q>>r; 

    string a,b,c;
    cin>>a>>b>>c; 
    
    int t[p+1][q+1][r+1];
    
    for(int i=0;i<p+1;i++){
        for(int j=0;j<q+1;j++){
            for(int k=0;k<r+1;k++){
                if(i==0 or j==0 or k==0){
                    t[i][j][k] = 0; 
                }
            }
        }
    }
    
    for(int i=1;i<p+1;i++){
        for(int j=1;j<q+1;j++){
            for(int k=1;k<r+1;k++){
                if(a[i-1]==b[j-1] and a[i-1]==c[k-1]){
                    t[i][j][k] = 1 +  t[i-1][j-1][k-1]; 
                }
                
                else{
                    t[i][j][k] = max(t[i-1][j][k],max(t[i][j-1][k],t[i][j][k-1])); 
                }
            }
        }
    }
    
    cout<<t[p][q][r];
}