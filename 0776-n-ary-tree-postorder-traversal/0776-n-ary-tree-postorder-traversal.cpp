/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(Node* root , vector<int>& res){
        vector<Node*> child = root->children;

        for(auto it: child){

            dfs(it,res);

        }

        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
    if(root == nullptr) return {};
     vector<int> res;

     dfs(root,res);

     return res;  
    }
};