#include<bits/stdc++.h>
using namespace std;

bool scrambled(string a,string b){
    if(a==b){
        return true; 
    }

    if(a.length() != b.length()){
        return false ; 
    }
    
    int n = a.length(); 

    if(n==0){
        return true ; 
    }

    for(int i=1;i<n;i++){
        if(scrambled(a.substr(0,i),b.substr(n-i,i)) and scrambled(a.substr(i,n-i),b.substr(0,n-i))){
            return true; 
        } 

        if( scrambled(a.substr(0,i),b.substr(0,i)) and scrambled(a.substr(i,n-i),b.substr(i,n-i))){
            return true; 
        }
    }

    return false; 
}

int main(){
    int n;
    cin>>n;

    string a;
    cin>>a;

    int m;
    cin>>m;

    string b;
    cin>>b;
   
    if(scrambled(a,b)){
        cout<<"SCRAMBLED"<<endl; 
    }

    else{
        cout<<"NOT SCRAMBLED"<<endl; 
    }

}