//! Leetcode Questions 2487. Remove Nodes From Linked List

//? link: https://leetcode.com/problems/remove-nodes-from-linked-list/?envType=daily-question&envId=2024-05-06

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode *rev(ListNode*head){
        ListNode *curr=head,*prev=NULL;
        while(curr!=NULL){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head=rev(head);
        ListNode *curr=head, *prev=NULL;
        int maxi=head->val;
        while(curr!=NULL){
            maxi=max(maxi,curr->val);
            if(maxi>curr->val){
                prev->next=curr->next;
            }
            else{
                prev=curr;
            }
            curr=curr->next;
        }
        head=rev(head);
        return head;
    }
};