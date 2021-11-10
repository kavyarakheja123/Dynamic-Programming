#include<bits/stdc++.h>
using namespace std;

int LCS(string x,string y,int n,int m){
    if(n==0 or m==0){
        return 0;
    }

    if(x[n-1]==y[m-1]){
        return 1 + LCS(x,y,n-1,m-1);
    }

    else{
        int ans1 = LCS(x,y,n-1,m);
        int ans2 = LCS(x,y,n,m-1);

        return max(ans1,ans2); 
    }
}

int main(){
    int n;
    cin>>n;

    string x;
    cin>>x ;  

    int m;
    cin>>m;

    string y;
    cin>>y; 
   
   cout<<LCS(x,y,n,m)<<endl; 
     
}