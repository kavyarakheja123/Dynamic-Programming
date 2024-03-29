#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int n, int arr[]){
    int lis[n];
       
    lis[0] = 1 ; 
       
    for(int i=1;i<n;i++){
        lis[i] = 1; 
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                lis[i] = max(lis[i],lis[j]+1); 
            }
        }
    }
       
    return *max_element(lis, lis + n);
}

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<longestSubsequence(n,arr); 
}