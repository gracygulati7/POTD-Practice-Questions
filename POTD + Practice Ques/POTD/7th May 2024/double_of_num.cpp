//! Leetcode Question 2816. Double a Number Represented as a Linked List

//? link: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/?envType=daily-question&envId=2024-05-07

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
    ListNode* doubleIt(ListNode* head) {
        string res = "";
        ListNode* curr = head;
        while (curr != NULL) {
            res += to_string(curr->val);
            curr = curr->next;
        }
        string s = doubleString(res);
        ListNode* newhead = NULL;
        ListNode* tail = NULL;
        for (int i = 0; i < s.size(); ++i) {
            char digit = s[i];
            ListNode* new_node = new ListNode(digit - '0');
            if (newhead == NULL) {
                newhead = new_node;
                tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }
        return newhead;
    }    
private:
    string doubleString(string num) {
        string result;
        int carry = 0;
        for (int i = num.size() - 1; i >= 0; --i) {
            int digit = (num[i] - '0') + carry;
            carry = digit / 10;
            result = to_string(digit % 10) + result;
        }
        if (carry > 0) {
            result = to_string(carry) + result;
        }
        return result;
    }
};
int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    ListNode* newhead = s.doubleIt(head);
    while (newhead != NULL) {
        cout << newhead->val << " ";
        newhead = newhead->next;
    }
    return 0;
}