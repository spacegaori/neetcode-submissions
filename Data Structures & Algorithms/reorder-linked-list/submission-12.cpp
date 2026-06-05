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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        slow->next = nullptr;
        ListNode* second = nullptr;
        while (curr) {
            ListNode* fwd = curr->next;
            curr->next = second;
            second = curr;
            curr = fwd;
        }
        
        ListNode* first = head;
        while (second) {
            ListNode* fwd1 = first->next;
            ListNode* fwd2 = second->next;

            first->next = second;
            second->next = fwd1;

            first = fwd1;
            second = fwd2;
        }
    }
};
