/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    }

    bool isValid(TreeNode* node, int left, int right) {
        if (!node) return true;

        if (!(left < node->val && node->val < right)) {
            return false;
        }

        return isValid(node->left, left, node->val) && isValid(node->right, node->val, right);
    }
};
