#include<bits/stdc++.h>
using namespace std;

string seen(vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]) return "YES";
        }
    }
    return "NO";
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<seen(arr)<<endl;
    }
    return 0;
}