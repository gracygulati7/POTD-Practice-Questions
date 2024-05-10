//! LeetCode Question 503. Next Greater Element II

//? link : https://leetcode.com/problems/next-greater-element-ii/description/ 

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n, -1); // Initialize the result array with -1 for all elements
        
        // Iterate over each element in the input array
        for (int i = 0; i < n; i++) {
            // Iterate from i+1 to i+n (circular traversal)
            for (int j = i + 1; j < i + n; j++) {
                // Use modulus operator to handle circular indexing
                if (nums[j % n] > nums[i]) { // If a greater element is found
                    next[i] = nums[j % n]; // Update the next greater element
                    break; // Break the inner loop
                }
            }
        }
        return next; // Return the result array
    }
};

int main(){
    Solution s;
    vector<int> nums={1,2,1};
    vector<int> ans=s.nextGreaterElements(nums);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" "; cout<<endl;
    return 0;
}