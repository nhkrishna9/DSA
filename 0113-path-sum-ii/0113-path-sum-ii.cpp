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
    void helper(TreeNode* root, int currSum, vector<int> curr, vector<vector<int>>& ans, int targetSum){
        if(root==nullptr){
            return;
        }
        
        curr.push_back(root->val);
        currSum = currSum + root->val;
        if(root->left == nullptr && root->right ==nullptr){
            if(currSum == targetSum){
                ans.push_back(curr);
            }
        }

        helper(root->left, currSum, curr, ans, targetSum);
        helper(root->right, currSum, curr, ans, targetSum);
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        helper(root, 0, {}, ans, targetSum);
        return ans;       
  
    }
};