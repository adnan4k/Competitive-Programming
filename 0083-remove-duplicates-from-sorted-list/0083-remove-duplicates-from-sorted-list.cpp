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
    ListNode* deleteDuplicates(ListNode* head) {
        // Special case...
        if(head==NULL || head->next==NULL)
            return head;
        // Initialize two pointers tmp(slow) and curr(fast)...
        ListNode* tmp = head;
        ListNode* curr = head->next;
        // Traverse all element through a while loop if curr node is not null...
        while(curr!=NULL) {
            // If the value of curr is equal to the value of tmp...
            // It means the value is present in the linked list...
            if(tmp->val == curr->val) {
                // Hence we do not need to include curr again in the linked list...
                // So we increment the value of curr...
                curr=curr->next;
            }
            // Otherwise, we increment both the pointers.
            else {
                tmp->next = curr;
                tmp = curr;
                curr = tmp->next;
            }
        }
        tmp->next = NULL;
        return head;        // Return the sorted linked list without any duplicate element...
    }
};