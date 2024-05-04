//! Leetcode Question 124. Binary Tree Maximum Path Sum

//? link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int maxsum=INT_MIN;
    int maxpath(TreeNode* root){
        if(root==NULL) return 0;
        int left=maxpath(root->left);
        int right=maxpath(root->right);
        int ans=max(root->val+right+left, max(root->val+left, max(root->val+right,root->val)));
        maxsum=max(maxsum,ans);
        return max(root->val, max(root->val+left,root->val+right));
    }
    int maxPathSum(TreeNode* root) {
        maxpath(root);
        return maxsum;
    }
};
int main(){
    Solution s;
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    cout<<s.maxPathSum(root);
    return 0;
}