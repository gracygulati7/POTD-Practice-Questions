//! GFG Question Nth node from end of linked list

//? link: https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

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
class Solution {
public:
    int getNthFromLast(Node *head, int n){
        Node* curr = head;
        int count = 0;
        // Count the number of nodes in the list
        while (curr != NULL) {
            curr = curr->next;
            count++;
        }
        // Check if n is greater than the length of the list
        if (n > count) {
            return -1;
        }
        curr = head;
        // Traverse the list until (count - n + 1) position
        for (int i = 0; i < count - n; i++) {
            curr = curr->next;
        }
        return curr->data;
    }
};
int main(){
    int t,n,k,i,l;
    cin>>t;
    while(t--){
        Node* head=NULL, *tail=NULL;
        cin>>n>>k;
        int val; cin>>val;
        head = new Node(val);
        tail=head;
        for(i=1;i<n;i++){
            cin>>l;
            tail->next = new Node(l);
            tail=tail->next;
        }
        Solution ob;
        cout<<ob.getNthFromLast(head,k)<<endl;
    }
    return 0;
}


//* if ques says not to calculate length of ll then code can be as follows:
/*
class Solution {
public:
    int getNthFromLast(Node *head, int k){
        if(head==NULL || k<=0) return -1;
        Node* fast=head, *slow=head;
        for(int i=0;i<k;i++){
            if(fast==NULL) return -1;
            fast=fast->next;
        }
        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        return slow->data;
    }
};  
*/