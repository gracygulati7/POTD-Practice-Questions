//! Leetcode Question 1480. Running Sum of 1d Array

//? link: https://leetcode.com/problems/running-sum-of-1d-array/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){ // iterate through nums array
            nums[i]=nums[i]+nums[i-1]; // store result of sum of previous elements in array inplace
            // we start from i=1 and not i=0 coz 1st element will be the same as there is no previous elemment to it 
            // so its sum will be first element itself
        }
        return nums; // return modified array
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3,4};
    vector<int> ans=s.runningSum(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}