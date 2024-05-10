//! Leetcode Question 104. Maximum Depth of Binary Tree

//? link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};
class Solution{
    public:
    int maxDepth(TreeNode* root){
        if(root==NULL) return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return max(left,right)+1;
    }
};
int main(){
    Solution s;
    TreeNode* root= new TreeNode(1);
    root->left= new TreeNode(2);
    root->right= new TreeNode(3);
    root->left->left= new TreeNode(4);
    root->left->right= new TreeNode(5);
    cout<<s.maxDepth(root)<<endl;
    return 0;
}