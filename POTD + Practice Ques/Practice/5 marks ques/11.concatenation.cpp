#include<bits/stdc++.h>
using namespace std;

void concat(string& s){
    unordered_map<char,int> freq;
    for(char c:s){
        freq[c]++;
    }
    for(char c:s){
        cout<<freq[c]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    std::cin>>t;
    while(t--){
        string str;
        std::cin>>str;
        concat(str);
    }
    return 0;
}