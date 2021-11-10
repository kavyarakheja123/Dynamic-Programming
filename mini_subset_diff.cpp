#include<bits/stdc++.h>
using namespace std;

bool static t[101][1001]; 


void subset_sum(int arr[],int n,int sum){
    for(int i=0;i<n+1;i++){
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
}

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];  
    }

    int range = accumulate(arr,arr+n,0); 
    
    memset(t,0,sizeof(t)); 
    subset_sum(arr,n,range); 

    vector<int> v ; 

    for(int i=0;i<=range/2;i++){
        if(t[n-1][i]==true){
            v.push_back(i); 
        }
    }

    int mini = INT_MAX;

    for(auto it: v){
        mini = min(mini,range-2*it); 
    }
    

    cout<<mini<<endl; 


}