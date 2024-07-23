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
    int pathSum(TreeNode* root , int &sum){

        if(root == nullptr) return 0;

        int lSum = max(0,pathSum(root->left,sum));
        int rSum = max(0,pathSum(root->right,sum));

        sum = max({lSum+rSum + root->val,sum});

        return max(lSum,rSum) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int sum = -1e9+7 ; 
        pathSum(root,sum);
        return sum;
    }
};