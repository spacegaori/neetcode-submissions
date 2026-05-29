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
    bool hasCycle(ListNode* head) {
        std::unordered_set<ListNode*> seen{};

        auto curr = head;
        while (curr) {
            if (!seen.insert(curr).second) {
                return true;
            }

            for (auto e : seen) {
                std::cout << e << ' ';
            }
            std::cout << '\n';

            curr = curr->next;
        }

        return false;
    }
};
