//! GeeksforGeeks Question Print all nodes that don't have a sibling 

//? Link: https://www.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1

#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
vector<int> noSibling(Node *node) {
    queue<Node *> q;
    vector<int> res;
    // If the node is NULL then it means there is no node in the tree so return empty vector
    if (node == NULL) {
        return res;
    }
    // push the root node into the queue
    q.push(node);
    // Traverse the tree level by level
    while (!q.empty()){
        Node *front = q.front();
        q.pop();
        // if the front node has both left child but no right child then push the left child data into the vector
        if (front->left != NULL){
            if (front->right == NULL){
                res.push_back(front->left->data);
            }
            // push the left child into the queue again to check if it has any sibling or not
            q.push(front->left);
        }
        // if the front node has both right child but no left child then push the right child data into the vector
        if (front->right != NULL){
            if (front->left == NULL){
                res.push_back(front->right->data);
            }
            q.push(front->right);
        }
    }
    // If the vector is empty then it means there is no node in the tree that don't have a sibling so return {-1}
    if (res.size() == 0) {
        return {-1};
    }
    else{
        // Sort the vector and return the vector
        sort(res.begin(), res.end());
        return res;
    }
}

int main(){
    // Example 1
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    vector<int> ans = noSibling(root);
    // Output: 4 5
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}