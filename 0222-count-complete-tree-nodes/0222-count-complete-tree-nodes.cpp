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
    int countNodes(TreeNode* root) {
        // queue<TreeNode*> q;

        // q.push(root);
        // int cnt = 0;

        // if(root == nullptr) return cnt;
        // while(!q.empty()){

        //     auto node = q.front();
        //     q.pop();
        //     cnt++;
        //     if(node->left) q.push(node->left);
        //     if(node->right) q.push(node->right);
        // }   

        // return cnt;

        if(root == nullptr) return 0;

        int lh = findLeft(root);
        int rh = findRight(root);

        if(lh == rh) return (1<<lh)-1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findLeft(TreeNode* root){
        int h = 0 ;
        while(root != nullptr){
            h++;
            root = root->left;
        }

        return h;
    }
    int findRight(TreeNode* root){
        int h = 0 ;
        while(root != nullptr){
            h++;
            root = root->right;
        }

        return h;
    }
};