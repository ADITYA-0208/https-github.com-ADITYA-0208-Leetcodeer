class Solution {
public:
    TreeNode* last = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val); 
    }

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (last && root->val < last->val) {
            if (!first) {
                first = last;
                second = root;
            } else {
                second = root;
            }
        }
        last = root;

        inorder(root->right);
    }
};
