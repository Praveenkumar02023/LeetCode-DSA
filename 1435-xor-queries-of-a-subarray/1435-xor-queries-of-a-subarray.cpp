class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
       int n = q.size();

        vector<int>res;

        vector<int>preXor(arr.size());
        int Xor = arr[0];
        preXor[0] = Xor;

        for(int i = 1 ; i < arr.size() ; i++){

            Xor ^= arr[i];
            preXor[i] = Xor;

        }   

        for(int i = 0 ; i < n ; i++){

            int low = q[i][0];
            int high = q[i][1];

            if(low == high){
                res.push_back(arr[low]);
            }else if(low == 0){

                res.push_back(preXor[high]);
            }else{

                res.push_back(preXor[high] ^ preXor[low-1]);
            }
        }    

        return res; 
    }
};