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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        TreeNode* node = root;

        while (root != nullptr) {
            if (root->right == nullptr) {
                sum += root->val;
                root->val = sum;
                root = root->left;
            } else {
                TreeNode* predecessor = root->right;
                while (predecessor->left != nullptr && predecessor->left != root) {
                    predecessor = predecessor->left;
                }

                if (predecessor->left == nullptr) {
                    predecessor->left = root;
                    root = root->right;
                } else {
                    sum += root->val;
                    root->val = sum;
                    predecessor->left = nullptr;
                    root = root->left;
                }
            }
        }
        return node;

    }
};