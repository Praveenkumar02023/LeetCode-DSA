class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res;
        int n = A.size();
        int cnt = 0 ;

        unordered_set<int> a,b;

        for(int i = 0 ; i < n ; i++ ){

            if(A[i] == B[i]){

                cnt++;
            }else{

                if(b.find(A[i]) != b.end()) cnt++;
                if(a.find(B[i]) != a.end()) cnt++;

            }

             a.insert(A[i]);
             b.insert(B[i]);

             res.push_back(cnt);
        }
        return res;
        
    }
};