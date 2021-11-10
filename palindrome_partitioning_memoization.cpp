#include<bits/stdc++.h>
using namespace std;

int static t[1001][1001]; 

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
        return 0; 
    }

    if(is_palindrome(s,i,j)==true){
        return 0; 
    }

    if(t[i][j] != -1){
        return t[i][j]; 
    }

    int mini = INT_MAX ; 

    for(int k=i;k<=j-1;k++){
        int left;
        int right;

        if(t[i][k] != -1){
            left = t[i][k]; 
        }

        else{
            left = partitions(s,i,k); 
        }

        if(t[k+1][j] != -1){
            right = t[k+1][j];
        }

        else{
            right = partitions(s,k+1,j); 
        }

        int temp = left + right + 1; 

        mini = min(mini,temp); 
    }

    return t[i][j] = mini; 
}

int main(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    memset(t,-1,sizeof(t)); 

    cout<<partitions(s,0,n-1)<<endl; 
}