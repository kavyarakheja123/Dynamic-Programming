#include<bits/stdc++.h>
using namespace std;

int floor(int e,int f){
    if(f==0 or f==1){
        return f; 
    }

    if(e==1){
        return f; 
    }

    int mini = INT_MAX;

    for(int k=1;k<=f;k++){
        int temp = 1 + max(floor(e-1,k-1),floor(e,f-k)); 

        mini = min(mini,temp); 
    }

    return mini; 
}

int main(){
    int e,f;
    cin>>e>>f;
    
    cout<<floor(e,f)<<endl; 

}