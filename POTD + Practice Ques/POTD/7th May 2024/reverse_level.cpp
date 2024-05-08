//! GeeksForGeeks Question Reverse Level Order Traversal

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
vector<int> reverseLevelOrder(Node *root) {
    if (!root) return {}; // Base Case: Check if the root is NULL
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> levels; // Store nodes of each level separately
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> levelNodes; // Nodes at current level
        for (int i = 0; i < levelSize; i++) {
            Node* front = q.front(); q.pop();
            levelNodes.push_back(front->data);
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
        levels.push_back(levelNodes); // Store nodes of current level
    }
    vector<int> reverseOrder;
    for (int i = levels.size() - 1; i >= 0; i--) { // insert nodes in reverse order
        reverseOrder.insert(reverseOrder.end(), levels[i].begin(), levels[i].end());
    }
    return reverseOrder;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> res = reverseLevelOrder(root);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}