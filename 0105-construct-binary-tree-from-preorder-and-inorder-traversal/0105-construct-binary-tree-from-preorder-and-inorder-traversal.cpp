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
    TreeNode* constructRoot(int in , int inEnd , int pre , int preEnd , unordered_map<int,int> & mp , vector<int>& inorder , vector<int>& preorder){

        if(in > inEnd || pre > preEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[pre]);

        int inDist = mp[root->val];
        int numsNode = inDist - in;
        root->left = constructRoot(in,inDist-1,pre+1,pre+numsNode,mp,inorder,preorder);
        root->right = constructRoot(inDist+1,inEnd, pre+numsNode+1,preEnd,mp,inorder,preorder);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;

        for(int i = 0 ; i < inorder.size() ; i++){

            mp[inorder[i]] = i;

        }

        return constructRoot(0,inorder.size()-1 , 0 ,preorder.size()-1, mp , inorder , preorder );
    }
};