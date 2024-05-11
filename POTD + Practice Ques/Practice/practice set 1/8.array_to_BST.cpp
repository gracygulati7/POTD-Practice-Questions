//! GeeksForGeeks Question Array to BST

//? link: https://www.geeksforgeeks.org/problems/array-to-bst4443/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left; Node* right;
    Node(int val): data(val), left(NULL), right(NULL) {};
};
Node* inordertobst(int start,int end,vector<int>& nums){
    if(start>end) return NULL;
    int mid=(start+end)/2;
    Node* root=new Node(nums[mid]);
    root->left=inordertobst(start,mid-1,nums);
    root->right=inordertobst(mid+1,end,nums);
    return root;
}
void pre(Node* root,vector<int>& ans){
    if(root==NULL) return;
    ans.push_back(root->data);
    pre(root->left,ans);
    pre(root->right,ans);
}
class Solution{
    public:
    vector<int> solve(vector<int>& nums){
        Node* root=NULL;
        root=inordertobst(0,nums.size()-1,nums);
        vector<int> ans;
        pre(root,ans);
        return ans;
    }
};
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        Solution s;
        vector<int> ans=s.solve(nums);
        for(auto i:nums){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}



//* Alternative Solution for same question in leetcode
//? link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

/*
class Solution{
    public:
    TreeNode* sortedArrayToBST(vector<int>& nums){
        int n=nums.size;
        if(n==0) return NULL;
        vector<int> left {}, right{};
        int mid=n/2;
        for(int i=0; i<nums.size();i++){
            if(i<mid){
                left.push_back(nums[i]);
            }
            else right.push_back(nums[i]);
        }
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=sortedArrayToBST(left);
        root->right=sortedArrayToBST(right);
        return root;
    }
}
*/