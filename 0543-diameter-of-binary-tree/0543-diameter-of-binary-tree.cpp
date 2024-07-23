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
    int height(TreeNode* root){
        if(root == nullptr) return 0;

        int l = 1 + height(root->left);
        int r = 1 + height(root->right);
       

        return max(l , r);
    }

    int maxHeight(TreeNode* root){
        if(root == nullptr) return 0;

        int lHeight = height(root->left);
        int rHeight = height(root->right);

        return max({(lHeight + rHeight) , maxHeight(root->left) , maxHeight(root->right)});
    }
    

    int diameterOfBinaryTree(TreeNode* root) {
        return maxHeight(root);
    }
};