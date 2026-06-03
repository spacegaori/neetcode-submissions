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
        if (!head || !head->next) return;

        auto slow = head;
        auto fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 0->1->2->3->4->5->6
        //          ^        ^
        //        slow     fast
        auto second = slow->next;
        slow->next = nullptr;
        // 0->1->2->3->4->5->6->nullptr
        //             ^     ^
        //          second fast
        // slow: 0->1->2->3->nullptr
        // TODO: reverse second

        auto curr = second;
        ListNode* prev = nullptr;
        while (curr) {
            auto fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }

        auto first = head;
        second = prev;
        while (second) {
            auto fwd1 = first->next;
            auto fwd2 = second->next;

            first->next = second;
            second->next = fwd1;

            first = fwd1;
            second = fwd2;
        }
    }
};
