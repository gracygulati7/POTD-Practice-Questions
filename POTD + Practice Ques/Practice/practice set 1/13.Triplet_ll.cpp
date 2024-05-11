//! Question Triplets From LL

//? link: https://www.geeksforgeeks.org/find-a-triplet-from-three-linked-lists-with-sum-equal-to-a-given-number/

#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
vector<int> triplets(Node* headA, Node* headB, Node* headC, int num){
    Node* a=headA; vector<int> ans{};
    while(a!=NULL){
        Node* b=headB; Node* c=headC;
        while(b!=NULL && c!=NULL){
            int sum=a->data+b->data+c->data;
            if(sum==num){
                ans.push_back(a->data);
                ans.push_back(b->data);
                ans.push_back(c->data);
                return ans; // Return the first triplet found
            }
            else if(sum<num){
                b=b->next;
            }
            else{
                c=c->next;
            }
        }
        a=a->next;
    }
    return ans; // Return an empty vector if no triplet is found
}
int main() {
    Node* headA = nullptr;
    Node* headB = nullptr;
    Node* headC = nullptr;

    // Input for linked list A
    int n;
    cout << "Enter the number of nodes for linked list A: ";
    cin >> n;
    cout << "Enter the values for linked list A: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (headA == nullptr) {
            headA = new Node(val);
        } else {
            Node* temp = headA;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Node(val);
        }
    }

    // Input for linked list B
    cout << "Enter the number of nodes for linked list B: ";
    cin >> n;
    cout << "Enter the values for linked list B: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (headB == nullptr) {
            headB = new Node(val);
        } else {
            Node* temp = headB;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Node(val);
        }
    }

    // Input for linked list C
    cout << "Enter the number of nodes for linked list C: ";
    cin >> n;
    cout << "Enter the values for linked list C: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (headC == nullptr) {
            headC = new Node(val);
        } else {
            Node* temp = headC;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Node(val);
        }
    }

    int targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    // Call the triplets function
    vector<int> result = triplets(headA, headB, headC, targetSum);

    // Print the result
    if (!result.empty()) {
        cout << "Triplet found: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "No triplet found with the given sum." << endl;
    }

    // Clean up memory (free allocated nodes)
    Node* temp;
    while (headA) {
        temp = headA;
        headA = headA->next;
        delete temp;
    }
    while (headB) {
        temp = headB;
        headB = headB->next;
        delete temp;
    }
    while (headC) {
        temp = headC;
        headC = headC->next;
        delete temp;
    }

    return 0;
}