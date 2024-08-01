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
    int inorder(TreeNode* root,int &cnt,int k){

        if(root == nullptr) return 1;

        if(inorder(root->left ,cnt,k) == -1) return -1;
        
        cnt++;
        if(cnt == k){
            cnt = root->val;
            return -1;
        }
       if(inorder(root->right,cnt,k) == -1) return -1;

       return 1;

    }
    int kthSmallest(TreeNode* root, int k) {
      int cnt = 0;

      inorder(root,cnt,k);

      return cnt;

    }
};