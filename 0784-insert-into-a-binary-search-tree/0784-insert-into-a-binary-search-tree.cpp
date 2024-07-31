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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }

        TreeNode* res = root;

        while(root != nullptr){

            if(root->val < val){
                if(root->right == nullptr){
                    TreeNode *temp = new TreeNode(val);
                    root->right = temp;
                    break;
                }

                root = root->right;
            }else{
                 if(root->left == nullptr){
                    TreeNode* temp = new TreeNode(val);
                    root->left = temp;
                    break;
                }

                root = root->left;
            }


        }
            return res; 
    }
};