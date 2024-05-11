//! Leetcode Question 450. Delete Node in a BST

//? link: https://leetcode.com/problems/delete-node-in-a-bst/description/

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
class Solution{
    public:
    TreeNode* deleteNode(TreeNode* root,int key){
        if(root==NULL) return NULL;
        if(root->val==key){
            if(root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode* right=root->right;
                while(right->left){
                    right=right->left;
                }
                swap(root->val,right->val);
            }
        }
        root->left=deleteNode(root->left,key);
        root->right=deleteNode(root->right,key);
        return root;
    }
};
int main(){
    Solution s;
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->right=new TreeNode(6);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);
    root->right->right=new TreeNode(7);
    root=s.deleteNode(root,3);
    return 0;
}