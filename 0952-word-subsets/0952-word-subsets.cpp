class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        int n = words1.size();
        int m = words2.size();

        vector<int> maxCharFreq(26,0);

        for(auto word : words2){
            
            vector<int> curCharFreq(26,0);

            for(auto ch : word){

                int idx = ch-'a';
                curCharFreq[idx]++;

            }

            for(int i = 0 ; i < 26 ; i++){
                maxCharFreq[i] = max(maxCharFreq[i] , curCharFreq[i]);
            }

        }

        vector<string> res;

        for(auto word : words1){

            vector<int> curCharFreq(26,0);

            for(auto ch : word){

                int idx = ch-'a';
                curCharFreq[idx]++;
            }

            bool take = true;

            for(int i = 0; i < 26 ; i++){

                if(maxCharFreq[i] > curCharFreq[i] ){
                    take = false;
                    break;
                }
            }

            if(take){
                res.push_back(word);
            }

        }      
        return res;
    }
};