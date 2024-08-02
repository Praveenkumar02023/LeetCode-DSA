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
// class BSTiterator {
//     stack<TreeNode*> st;
//     bool reverse = true;

// public:
//     BSTiterator(TreeNode* root, bool isReverse) {
//         reverse = isReverse;
//         if (reverse) {
//             while (root != nullptr) {
//                 st.push(root);
//                 root = root->right;
//             }
//         }else{
//              while (root != nullptr) {
//                 st.push(root);
//                 root = root->left;
//             }
//         }
//     }

//     TreeNode* next(){
//         TreeNode* temp = st.top();
//        TreeNode* res = temp;
//         st.pop();
//         if(reverse){
//             temp = temp->left;
//             while(temp != nullptr){
//                 st.push(temp);
//                 temp = temp->right;
//             }
//         }else{
//              temp = temp->right;
//             while(temp != nullptr){
//                 st.push(temp);
//                 temp = temp->left;
//             }
//         }

//         return res;
//     }
// };

class Solution {
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
public:
    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;

        inorder(root->left);
       if(prev != nullptr && root->val < prev->val){

        if(first == nullptr){
            first = prev;
            middle = root;
        }
        else{
            last = root;
        }
       }
       prev = root;

     inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        

      first = middle = last = nullptr;

        inorder(root);

        if(first && last) swap(first->val,last->val);

        else if(first && middle) swap(first->val,middle->val);
    }
};