//! GeeksForGeeks Question K distance from root

//? link: https://www.geeksforgeeks.org/problems/k-distance-from-root/1

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution {
public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k) {
        int count = 0;
        vector<int> res;
        if (root == NULL)
            return res;
        // If k is 0 then push the root data to the res vector and return the res vector
        if (k == 0) {
            res.push_back(root->data);
            return res;
        }
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            Node *front = q.front();
            q.pop();
            if (front == NULL) { // If front is NULL means we have traversed all the nodes of the current level        
                k--; // Decrement k because we have traversed one level
                /*
                We decrement the value of k. This is because each time we encounter a
                NULL node, it signifies the end of a level in the tree. So, we decrement k
                to keep track of how many levels we have traversed.
                */

                if (k == 0)  // If k is 0 means we have reached the kth level
                    break;
                q.push(NULL); // Push NULL to the queue to mark the end of the level and to keep track of the other levels
            }
            else {
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
        }
        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();
            res.push_back(front->data);
        }
        return res;
    }
};
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution ob;
    vector<int> ans = ob.Kdistance(root, 2);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}