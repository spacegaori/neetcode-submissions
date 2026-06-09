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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        while (n > 0 && first) {
            first = first->next;
            n--;
        }

        ListNode dummy(0, head);
        ListNode* second = &dummy;
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;


        return dummy.next;
    }
};
