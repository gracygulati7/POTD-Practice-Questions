//! Leetcode Quetion 2. Add Two Numbers

//? link: https://leetcode.com/problems/add-two-numbers/description/

#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};
class Solution{
    public:
    ListNode* add(ListNode* l1,ListNode* l2){
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy; int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int digit1=(l1==NULL)?0:l1->val;
            int digit2=(l2==NULL)?0:l2->val;
            int sum=digit1+digit2+carry;
            int digit=sum%10; carry=sum/10;
            ListNode* node=new ListNode(digit);
            tail->next=node; tail=tail->next;
            l1=(l1==NULL)?NULL:l1->next;
            l2=(l2==NULL)?NULL:l2->next;
        }
        ListNode* res=dummy->next;
        delete dummy;
        return res;
    }
};