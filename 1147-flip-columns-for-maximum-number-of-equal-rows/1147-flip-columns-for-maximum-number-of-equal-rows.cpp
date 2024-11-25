class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> hmap;

        for(auto &row : matrix){

            int top = row[0];
            string pattern = "";
            for(int i = 0 ; i < row.size() ; i++){
                    if(row[i] == top) pattern += '1';
                    else pattern += '0';
            }
            
            hmap[pattern] += 1;
        }

        int res = 0;
        for(auto & it : hmap){
            res = max(res,it.second);
        }

        return res;
    }
};