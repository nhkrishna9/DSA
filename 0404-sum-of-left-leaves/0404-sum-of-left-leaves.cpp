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
    int sum=0;
public:
    void helper(TreeNode* root){
        if(root == nullptr){
            return;
        }
        if(root->left!= nullptr && root->left->left==nullptr && root->left->right==nullptr){
            sum = sum + root->left->val;
        }
        helper(root->left);
        helper(root->right);

    }
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root);
        return sum;
    }
};