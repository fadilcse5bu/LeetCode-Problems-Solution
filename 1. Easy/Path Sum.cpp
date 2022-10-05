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
    bool find(TreeNode* node, int sum, int targetSum) {
        if(node == NULL) return false;
        if(node->left == NULL && node->right == NULL && sum + node->val == targetSum) {
            return true;
        }
        bool f1 = find(node->left, sum + node->val, targetSum);
        bool f2 = find(node->right, sum + node->val, targetSum);
        
        return f1|f2;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return find(root, 0, targetSum);
    }
};
