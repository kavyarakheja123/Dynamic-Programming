/* This problem can also be asked as target sum problem, where we have to assign +/- to each of the
array element such that sum of elements is equal to a given value */

#include<bits/stdc++.h>
using namespace std;

int static t[101][1001]; 

void count_subsets(int arr[],int n,int sum){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j] = 0 ; 
            }

            if(j==0){
                t[i][j] = 1; 
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
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

    int diff;
    cin>>diff;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i]; 
    }

    int total_sum = accumulate(arr,arr+n,0); 

    int sum = (diff + total_sum)/2 ; 

    count_subsets(arr,n,sum); 

    cout<<t[n][sum]<<endl; 
}