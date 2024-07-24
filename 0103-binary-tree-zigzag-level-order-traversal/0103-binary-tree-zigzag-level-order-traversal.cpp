/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        bool flag = true;
        if (root == nullptr)
            return res;

        q.push(root);

        while (!q.empty()) {

            int size = q.size();
            vector<int> temp(size);


            for (int i = 0; i < size; i++) {

                TreeNode* top = q.front();
                q.pop();

                int idx = (flag) ? i : (size-1-i);

                temp[idx] = top->val;       

                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }

            res.push_back(temp);
            flag = !flag;
        }

        return res;
    }
};