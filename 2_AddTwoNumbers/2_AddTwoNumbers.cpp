#include <bits/stdc++.h>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node to simplify list creation
        // 'curr' will build the result list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carry = 0; // stores carry from each digit addition

        // Process nodes until BOTH lists are completely traversed
        while (l1 || l2) {

            // Take values from nodes, or 0 if that list is finished
            int val1 = (l1) ? l1->val : 0;
            int val2 = (l2) ? l2->val : 0;

            // Add digits + carry
            int sum = val1 + val2 + carry;

            // Update carry for the next iteration
            carry = sum / 10;

            // Create a new node with the last digit of sum
            curr->next = new ListNode(sum % 10);

            // Move forward in the result list
            curr = curr->next;

            // Move to next nodes in input lists if available
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        // If carry remains (ex: 9+9 creates carry 1)
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }

        // Result starts from dummy->next
        return dummy->next;
    }
};