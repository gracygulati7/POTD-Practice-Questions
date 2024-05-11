#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left; TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

TreeNode* solve(vector<int>& arr){
    if(arr.empty() || arr[0]==-1) return NULL;
    int idx=1; TreeNode* root=new TreeNode(arr[0]);
    queue<TreeNode*> q; q.push(root);
    while(!q.empty() && idx<arr.size()){
        TreeNode* front=q.front(); q.pop();
        if(arr[idx]!=-1){
            front->left=new TreeNode(arr[idx]);
            q.push(front->left);
        }
        idx++;
        if(idx<arr.size() && arr[idx]!=-1){
            front->right=new TreeNode(arr[idx]);
            q.push(front->right);
        }
        idx++;
    }
    return root;
}

//* left->right->root
void postorder(TreeNode* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            string ele; cin>>ele;
            if(ele=="null") v[i]=-1;
            else v[i]=stoi(ele);
        }
        TreeNode* root=solve(v);
        postorder(root);
        cout<<endl;
    }
    return 0;
}