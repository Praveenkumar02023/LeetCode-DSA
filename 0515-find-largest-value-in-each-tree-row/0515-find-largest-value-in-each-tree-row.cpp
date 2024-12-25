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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr)return{};

        vector<int> res;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int largestValue = INT_MIN;
            int levelSize = q.size();
            while(levelSize--){

                TreeNode* frontNode =  q.front();
                q.pop();
                largestValue = max(largestValue,frontNode->val);

                if(frontNode->left)q.push(frontNode->left);
                if(frontNode->right)q.push(frontNode->right);

            }
            res.push_back(largestValue);
        } 
        return res;
    }
};