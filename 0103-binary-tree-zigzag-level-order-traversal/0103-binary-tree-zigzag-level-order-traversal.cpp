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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL)  return {};
        q.push(root);
        vector<vector<int>>levelorder;
        int k=0;
        while(!q.empty()){
            int n=q.size();
            vector<int>ans;
            for(int i=0;i<n;i++){
                auto top=q.front();
                q.pop();

                if(top->left!=NULL){
                    q.push(top->left);
                }  
                if(top->right!=NULL){
                    q.push(top->right);
                }
                ans.push_back(top->val);        
            }
            if(k%2==0) levelorder.push_back(ans);
            else{reverse(ans.begin(),ans.end());  levelorder.push_back(ans);}
            k++;
        }
        return levelorder;
    }
};