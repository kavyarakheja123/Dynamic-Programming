#include<bits/stdc++.h>
using namespace std;

int paranthesis(string s,int i,int j,bool istrue){
    if(i>j){
        return false; 
    }

    if(i==j){
        if(istrue==true){
            return s[i]=='T'; 
        }

        else{
            return s[i]=='F'; 
        }
    }
    
    int ans = 0; 

    for(int k=i+1;k<=j-1;k+=2){
        int left_true = paranthesis(s,i,k-1,true);
        int left_false = paranthesis(s,i,k-1,false); 

        int right_true = paranthesis(s,k+1,j,true);
        int right_false = paranthesis(s,k+1,j,false);

        if(s[k]=='|'){
            if(istrue==true){
                ans += left_true*right_true + left_true*right_false + left_false*right_true; 
            }

            else{
                ans += left_false*right_false; 
            }
        }

        else if(s[k]=='&'){
            if(istrue==true){
                ans += left_true*right_true; 
            }

            else{
                ans += left_true*right_false + left_false*right_true + left_false*right_false; 
            }
        }

        else if(s[k]=='^'){
            if(istrue==true){
                ans += left_true*right_false + left_false*right_true; 
            }

            else{
                ans += left_false*right_false + left_true*right_true; 
            }
        }
    }

    return ans; 
}

int main(){
    string s;
    cin>>s;

    cout<<paranthesis(s,0,s.length()-1,true); 

}