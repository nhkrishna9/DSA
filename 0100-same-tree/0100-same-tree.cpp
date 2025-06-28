class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base cases
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;

        // Recursive check for left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
