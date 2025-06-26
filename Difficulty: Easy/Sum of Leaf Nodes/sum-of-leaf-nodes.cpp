/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.
class Solution {
    int ans=0;
    void helper(Node* root){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            ans += root->data;
        }
        helper(root->left);
        helper(root->right);
    }
  public:
    int leafSum(Node* root) {
        // code here
        helper(root);
        return ans;
    }
};