/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void fillParent(unordered_map<TreeNode* , TreeNode*>& parent , TreeNode* & root){

        if(root == nullptr) return ;

        if(root->left){
            parent[root->left] = root;
            fillParent(parent,root->left);
        }

        if(root->right){
            parent[root->right] = root;
            fillParent(parent,root->right);
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent;
        fillParent(parent,root);

        unordered_map<TreeNode* , bool> visited;

        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;

        int dist = 0;
        while(!q.empty()){
            int size = q.size();

            if(dist++ == k) break;

            for(int i = 0 ;  i < size ; i++){
                TreeNode* front = q.front();
                q.pop();

                if(front->left && !visited[front->left]){
                    visited[front->left] = true;
                    q.push(front->left);
                }

                if(front->right && !visited[front->right]){
                    visited[front->right] = true;
                    q.push(front->right);
                }

                if(parent[front] && !visited[parent[front]]){
                    visited[parent[front]] = true;
                    q.push(parent[front]);
                }

            }

        }
        vector<int> res;

        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }
};