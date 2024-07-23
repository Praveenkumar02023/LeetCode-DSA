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
    int height(TreeNode* root,int& maxi){
        if(root == nullptr) return 0;

        int l = height(root->left,maxi);
        int r = height(root->right,maxi);
        maxi = max(maxi,l+r);

        return 1 + max(l , r);
    }

    // int maxHeight(TreeNode* root){
    //     if(root == nullptr) return 0;

    //     int lHeight = height(root->left);
    //     int rHeight = height(root->right);

    //     return max({(lHeight + rHeight) , maxHeight(root->left) , maxHeight(root->right)});
    // }
    

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        height(root,maxi);
        return maxi;
    }
};