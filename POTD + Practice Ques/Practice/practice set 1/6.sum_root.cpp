//! Leetcode Question 129. Sum Root to Leaf Numbers

//? link: https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x) , left(NULL), right(NULL){}
};
class Solution{
    public:
    int sum(TreeNode* root){
        return dfs(root,0);
    }
    int dfs(TreeNode *root,int sum){
        if(root==NULL) return 0;
        int sum=sum*10+root->val;
        if(root->right==NULL && root->left==NULL) return sum;
        return dfs(root->left,sum)+dfs(root->right,sum);
    }
};
int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    Solution s;
    cout<<s.sum(root)<<endl;
    return 0;
}