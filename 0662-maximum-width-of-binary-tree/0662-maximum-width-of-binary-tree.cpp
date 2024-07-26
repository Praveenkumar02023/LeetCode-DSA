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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,unsigned long long>> q;

        q.push({root,0});

        int ans = 0 ;

        while(!q.empty()){

            int size = q.size();
            unsigned long long minn = q.front().second;
            unsigned long long start , end;

            for(int i = 0 ; i < size ; i++){
                unsigned long long cur_idx = q.front().second-minn;
                TreeNode* node = q.front().first;

                q.pop();

                if(i==0) start = cur_idx;
                if(i==size-1) end = cur_idx;

                if(node->left) q.push({node->left,cur_idx*2+1});
                if(node->right) q.push({node->right,cur_idx*2+2});
            }

            ans = max(ans,static_cast<int>(end-start+1));

        }
        return ans;
    }
};