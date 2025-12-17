#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;                // value stored in the node
 *     ListNode *next;         // pointer to the next node
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    // Splits the linked list into two halves
    // Returns the head of the second half
    ListNode* splitList(ListNode* head) {
        // Fast pointer moves two steps at a time
        // Slow pointer moves one step at a time
        ListNode* fast = head->next;
        ListNode* slow = head;

        // When fast reaches the end,
        // slow will be at the middle
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Second half starts from slow->next
        ListNode* second = slow->next;

        // Break the list into two halves
        slow->next = nullptr;

        return second;
    }

    // Merges two sorted linked lists into one sorted list
    ListNode* merge(ListNode* first, ListNode* second) {
        // If one list is empty, return the other
        if (first == nullptr) return second;
        if (second == nullptr) return first;

        // Choose the smaller value node
        if (first->val <= second->val) {
            // Recursively merge the remaining lists
            first->next = merge(first->next, second);
            return first;
        } else {
            second->next = merge(first, second->next);
            return second;
        }
    }

    // Performs merge sort on the linked list
    ListNode* mergeSort(ListNode* head) {
        // Base case: empty list or single node is already sorted
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Split the list into two halves
        ListNode* second = splitList(head);

        // Recursively sort both halves
        head = mergeSort(head);
        second = mergeSort(second);

        // Merge the two sorted halves
        return merge(head, second);
    }

    // Main function called by LeetCode
    ListNode* sortList(ListNode* head) {
        // Apply merge sort on the linked list
        return mergeSort(head);
    }
};