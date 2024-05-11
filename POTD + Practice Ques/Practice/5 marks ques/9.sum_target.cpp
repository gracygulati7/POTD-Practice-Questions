#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& arr,int n){
    int m=arr.size();
    vector<int> ans(2,-1);
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            int sum=arr[i]+arr[j];
            if(sum==n){
                ans[0]=i;
                ans[1]=j;
                return ans;
            }
        }
    }
    return ans;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
        cin>>arr[i];
        }
        int target; cin>>target;
        vector<int> ans=solve(arr,target);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}