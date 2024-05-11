#include<bits/stdc++.h>
using namespace std;

int majority(vector<int>& arr){
    sort(arr.begin(),arr.end());
    return arr[arr.size()/2];
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<majority(arr)<<endl;
    }
    return 0;
}