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
    void getLeafNodes(TreeNode* root, vector<int>& ans){
        if(root==nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(root->val);
        }
        getLeafNodes(root->left, ans);
        getLeafNodes(root->right, ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1LeafNodes;
        vector<int> t2LeafNodes;
        getLeafNodes(root1, t1LeafNodes);
        getLeafNodes(root2, t2LeafNodes);

        return std::equal(t1LeafNodes.begin(), t1LeafNodes.end(), t2LeafNodes.begin(), t2LeafNodes.end());
    }
};