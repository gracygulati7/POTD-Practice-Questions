#include<bits/stdc++.h>
using namespace std;

void intersection(vector<int>& arr1, vector<int>& arr2){
    unordered_set<int> s(arr1.begin(), arr1.end());
    for(int i=0;i<arr2.size();i++){
        if(s.find(arr2[i])!=s.end()){
            cout<<arr2[i]<<" ";
        }
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int m; cin>>m;
        vector<int> arr1(n), arr2(m);
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        for(int i=0;i<m;i++){
            cin>>arr2[i];
        }
        intersection(arr1,arr2);
        cout<<endl;
    }
    return 0;
}