#include<bits/stdc++.h>
using namespace std;

static unordered_map<string,bool> m;

bool scrambled(string a,string b){
    if(a==b){
        return true ; 
    }

    if(a.length() != b.length()){
        return false ; 
    }

    int n = a.length();

    if(n==0){
        return true ; 
    }

    string temp = a + " " + b; 
    if(m.find(temp) != m.end()){
        return m[temp]; 
    }

    for(int i=1;i<n;i++){
        if(scrambled(a.substr(0,i),b.substr(n-i,i)) and scrambled(a.substr(i,n-i),b.substr(0,n-i))){
            return m[temp] = true ; 
        }

        if(scrambled(a.substr(0,i),b.substr(0,i)) and scrambled(a.substr(i,n-i),b.substr(i,n-i))){
            return m[temp] = true ; 
        }
    }

    return m[temp] = false ; 
}

int main(){
    string a;
    cin>>a;

    string b;
    cin>>b;

    if(scrambled(a,b)){
        cout<<"SCRAMBLED"<<endl; 
    }

    else{
        cout<<"NOT SCRAMBLED"<<endl; 
    }

}