class Solution {
public:
    void f(int i , int row , vector<int>& lastRow,vector<vector<int>>& res){


        if(i == row){
            res[row].push_back(1);
            return;
        }
        if(i == 0){
            res[row].push_back(1);
        }
        else{

        int num = lastRow[i-1] + lastRow[i];
        res[row].push_back(num);
        }
        f(i+1,row,lastRow,res); 
        

    }

    vector<vector<int>> generate(int numRows) {
         vector<vector<int>> res(numRows);
         res[0].push_back({1});
        if(numRows == 1) return res;
         res[1].push_back(1);
         res[1].push_back(1);

       
        if(numRows == 2) return res;

       

        for(int i = 2 ; i < numRows ; i++){
            f(0,i,res[i-1],res);
        }

        return res;
    }
};