//! Leetcode Question 236. Lowest Common Ancestor of a Binary Tree

//? link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
    public:
    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q) {
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        TreeNode* left=lca(root->left,p,q);
        TreeNode* right=lca(root->right,p,q);
        if(left!=NULL && right!=NULL) return root;
        if(left==NULL) return right;
        return left;
    } 
};
int main(){
    
}