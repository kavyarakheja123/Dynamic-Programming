#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n; 

    int sum;
    cin>>sum;

    int coin[n]; 

    for(int i=0;i<n;i++){
        cin>>coin[i]; 
    }

    int t[n+1][sum+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j==0){
                t[i][j] = 0 ; 
            }

            if(i==0){
                t[i][j] = INT_MAX-1 ; 
            }
        }
    }

    for(int j=1;j<sum+1;j++){
        if(j%coin[0]==0){
            t[1][j] = j/coin[0]; 
        }

        else{
            t[1][j] = INT_MAX-1 ; 
        }
    }

    for(int i=2;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j){
                int ans1 = 1 + t[i][j-coin[i-1]]; 
                int ans2 = t[i-1][j] ;

                t[i][j] = min(ans1,ans2); 
            }

            else{
                t[i][j] = t[i-1][j]; 
            }
        }
    }

    cout<<t[n][sum]<<endl; 
}