#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& arr){
    int n=arr.size();
    vector<int> res(n,0);
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(i!=j && arr[j]<arr[i]){
                count++;
            }
        }
        res[i]=count;
    }
    return res;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){ 
            cin>>arr[i];
        }
        vector<int>ans=solve(arr);
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}