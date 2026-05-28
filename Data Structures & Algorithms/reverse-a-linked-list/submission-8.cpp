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
    ListNode* reverseList(ListNode* head) {
        //      o -> o -> o -> o -> x
        //      ^
        //    head
        // x <- o <- o <- o <- o
        //                     ^
        //                   tail
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};
