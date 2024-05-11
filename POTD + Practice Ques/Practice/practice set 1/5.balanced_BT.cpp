//! Leetcode Question 110. Balanced Binary Tree

//? link: https://leetcode.com/problems/balanced-binary-tree/description/

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Soltuion{
    public:
    bool isBalanced(TreeNode* root){
        if(root==NULL) return true;
        if(height(root)==-1) return false;
        return true;
    }
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int left=height(root->left);
        int right=height(root->right);
        if(left==-1 || right==-1) return -1;
        if(abs(left-right)>1) return -1;
        return max(left,right)+1;
    }
};
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    Soltuion s;
    cout<<s.isBalanced(root)<<endl;
    return 0;
}