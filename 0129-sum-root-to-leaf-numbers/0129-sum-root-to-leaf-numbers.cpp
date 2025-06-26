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
    void helper(TreeNode* root, int num, int& ans){
        if(root==nullptr){
            return;
        }
        
        num = num*10 + root->val;
        if(root->left == nullptr && root->right ==nullptr){
            ans+=num;
        }

        helper(root->left, num, ans);
        helper(root->right, num, ans);
        
    }
    int sumNumbers(TreeNode* root) {
        int ans{0};
        helper(root, 0, ans);
        return ans;
    }
};