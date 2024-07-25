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
    void rightView(int y , TreeNode* root, map<int,int>& mp ){

        if(root == nullptr) return ;
        
        mp[abs(y)] = root->val;

        rightView(y+1 ,root->left,mp);
        rightView(y+1 ,root->right,mp);

    }
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> mp;
        vector<int> res;

        rightView(0,root,mp);

        for(auto it = mp.begin() ; it != mp.end() ; it++){
            res.push_back(it->second);
        }

        return res;
    }
};