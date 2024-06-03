/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* l3 = new ListNode();
        ListNode* result = l3;
        while (l1 != NULL || l2 != NULL || carry){
            int sum=0;
            if (l1!= NULL){
                sum += l1->val;
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2-> next;
            }
            sum += carry;
            carry = sum / 10;
            l3 -> next = new ListNode(sum % 10);
            l3 = l3->next;
        }
        return result->next;
    }
};