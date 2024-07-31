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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;

        TreeNode* node = root;

        while(node != nullptr){

            if(node->left == nullptr){
                pre.push_back(node->val);
                node = node->right;
            }else{

                TreeNode* prev = node->left;
                while(prev->right && prev->right != node){
                    prev = prev->right;
                }

                if(prev->right == nullptr){
                    prev->right = node;
                    pre.push_back(node->val);
                    node = node->left;
                }else{
                    prev->right = nullptr;
                    node = node->right;
                }
            }

        }

        return pre;
    }
};