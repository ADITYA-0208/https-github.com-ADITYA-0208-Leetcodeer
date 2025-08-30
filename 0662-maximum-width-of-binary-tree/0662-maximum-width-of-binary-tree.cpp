class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            long long minIndex = q.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < size; ++i) {
                auto [node,it] = q.front();
                q.pop();
                it=it-minIndex;
                if (i == 0) first =it;
                if (i == size - 1) last = it;
                
                if (node->left) q.push({node->left, 2 *it + 1});
                if (node->right) q.push({node->right, 2 *it + 2});
            }

            maxWidth = max(maxWidth, (int)(last - first + 1));
        }

        return maxWidth;
    }
};
