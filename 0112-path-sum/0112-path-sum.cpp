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
    void helper(TreeNode* root, int curr, bool& ans, int targetSum){
        if(root==nullptr || ans){
            return;
        }
        
        curr = curr + root->val;
        if(root->left == nullptr && root->right ==nullptr){
            if(curr == targetSum){
                ans |= true;
            }
        }

        helper(root->left, curr, ans, targetSum);
        helper(root->right, curr, ans, targetSum);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans{false};
        helper(root, 0, ans, targetSum);
        return ans;       
    }
};