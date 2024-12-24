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
    int SwapToSort(vector<int> curGroup){
        int n = curGroup.size();
        
        unordered_map<int,int> indexMap;
        
        for(int i = 0; i < n ; i++){
            indexMap[curGroup[i]] = i;
        }
        
        vector<int> curSortedGroup(curGroup.begin(),curGroup.end());
        
        sort(curSortedGroup.begin(),curSortedGroup.end());

        int totalOp = 0;
        for(int i = 0 ; i < n ; i++){

            if(curSortedGroup[i] == curGroup[i])continue;
            else{
                //get current unsorted value from curGroup and current value that should be in this place from cur Sorted array.
                int curUnsortedValue = curGroup[i];
                int curSortedValue = curSortedGroup[i];

                //get index of required value from hashMap such that we can swap.
                int curIndex = indexMap[curSortedValue];

                swap(curGroup[curIndex],curGroup[i]);

                //update new index in hashMap
                indexMap[curUnsortedValue] = curIndex;
                indexMap[curSortedValue] = i;
                totalOp += 1;
            }

        }
        return totalOp;

    }

    int minimumOperations(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int totalOp = 0;

        while(!q.empty()){
            vector<int> curLevelGroup;
            int k = q.size();
            while(k--){

                TreeNode* topNode = q.front();
                curLevelGroup.push_back(topNode->val);
                q.pop();
                
                if(topNode->left)q.push(topNode->left);
                if(topNode->right)q.push(topNode->right);
            }

            int reqOperation = SwapToSort(curLevelGroup);

            totalOp += reqOperation;
        }

        return totalOp;
    }
};