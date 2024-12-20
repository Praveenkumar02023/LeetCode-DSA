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
    void dfs(TreeNode* Left,TreeNode* Right,int level){

        if(Left == nullptr || Right == nullptr) return;

        if(level % 2 == 1){
            int temp = Left->val;
            Left->val = Right->val;
            Right->val = temp;
        }
        
        dfs(Left->left , Right->right , level + 1);
        dfs(Left->right , Right->left , level + 1);

    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left,root->right,1);

        return root;
    }
};