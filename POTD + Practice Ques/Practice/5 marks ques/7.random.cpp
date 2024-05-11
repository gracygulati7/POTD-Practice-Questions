#include<bits/stdc++.h>
using namespace std;

char letter(string s,string t){
    int n=s.length(), m=t.length(); int i=0;
    while(i<n && i<m){
        if(s[i]!=t[i]){
            return t[i];
        }
        i++;
    }
    return t[i];
}

int main(){
    int t; cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        cout<<letter(s,t)<<endl;
    }
    return 0;
}