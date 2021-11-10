#include<bits/stdc++.h>
using namespace std;

int static t[101][101]; 

int LCS(string x,int n,string y,int m){
    if(n==0 or m==0){
        return 0 ; 
    }

    if(t[n][m] != -1){
        return t[n][m]; 
    }

    if(x[n-1]==y[m-1]){
        return t[n][m] = 1 + LCS(x,n-1,y,m-1); 
    }

    else{
        int ans1 = LCS(x,n-1,y,m);
        int ans2 = LCS(x,n,y,m-1); 

        return t[n][m] = max(ans1,ans2); 
    }
}

int main(){
    int n;
    cin>>n;

    string x;
    cin>>x;

    int m;
    cin>>m;

    string y;
    cin>>y; 

    memset(t,-1,sizeof(t)); 

    LCS(x,n,y,m);

    cout<<t[n][m]<<endl; 
}