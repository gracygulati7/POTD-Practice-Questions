//! GeeksForGeeks Question Root to Leaf Paths

//? link: https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> dir;
        vector<int> res;
        solve(root,dir,res);
        return dir;
    }
    void solve(Node* root,vector<vector<int>>& dir,vector<int>& res){
        if(root==NULL) return;
        res.push_back(root->data);
        if(root->left==NULL && root->right==NULL){
            dir.push_back(res);
        }
        solve(root->left,dir,res);
        solve(root->right,dir,res);
        res.pop_back();
    }
};
int main(){
    Solution s;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<vector<int>> dir = s.Paths(root);
    for(int i=0;i<dir.size();i++){
        for(int j=0;j<dir[i].size();j++){
            cout<<dir[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}