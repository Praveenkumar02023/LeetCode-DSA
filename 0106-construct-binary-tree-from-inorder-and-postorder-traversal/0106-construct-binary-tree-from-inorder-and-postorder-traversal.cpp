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
    TreeNode* constructRoot(vector<int>& inorder, int in , int inEnd , vector<int>& postorder,int post , int postEnd ,unordered_map<int,int> &mpp ){

        if(in > inEnd || post < postEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[post]);

        int rootidx = mpp[root->val];
        int numsNode = inEnd-rootidx;

        root->left = constructRoot(inorder,in,rootidx-1,postorder,post-numsNode-1,postEnd,mpp);
        root->right = constructRoot(inorder,rootidx+1,inEnd,postorder,post-1,post-numsNode,mpp);

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int,int>mpp;
        for(int i = 0 ; i < inorder.size() ; i++){
            mpp[inorder[i]] = i;
        }

        return constructRoot(inorder,0,inorder.size()-1,postorder , postorder.size()-1,0,mpp);

    }
};