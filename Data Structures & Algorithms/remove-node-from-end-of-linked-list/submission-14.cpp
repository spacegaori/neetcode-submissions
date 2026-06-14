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
        if (!head->next) return nullptr;
        ListNode dummy{};
        dummy.next = head;
        ListNode* first = head;
        ListNode* second = &dummy;
        while (n && first) {
            first = first->next;
            n--;
        }

        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;

        return dummy.next;
    }
};
