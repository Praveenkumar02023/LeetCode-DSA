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
    void fillArr(TreeNode* root, vector<int>& res) {
        if (root == nullptr)
            return ;

        fillArr(root->left, res);
        res.push_back(root->val);
        fillArr(root->right, res);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> res;

        fillArr(root, res);

        int i = 0, j = res.size() - 1;

        while (i < j) {
            if (res[i] + res[j] > k)
                j--;
            else if (res[i] + res[j] < k)
                i++;
            else
                return true;
        }

        return false;
    }
}

;