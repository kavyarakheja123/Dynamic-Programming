#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string s,int i,int j){
    while(i<=j){
        if(s[i] != s[j]){
            return false ; 
        }
        i++;
        j--; 
    }

    return true; 
}

int partitions(string s,int i,int j){
    if(i>=j){
        return 0 ; 
    }

    if(is_palindrome(s,i,j)==true){
        return 0; 
    }
    
    int mini = INT_MAX; 
    for(int k=i;k<=j-1;k++){
        int temp = partitions(s,i,k) + partitions(s,k+1,j) + 1 ; 

        mini = min(mini,temp); 
    }

    return mini;
}

int main(){
    int n;
    cin>>n; 

    string s;
    cin>>s;

    cout<<partitions(s,0,n-1); 
}