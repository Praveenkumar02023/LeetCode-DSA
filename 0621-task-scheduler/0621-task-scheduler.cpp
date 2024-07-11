class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);

        priority_queue<int> pq;

        for(char c : tasks){
            freq[c-'A']++;
        }

        for(int x : freq){
            if(x){
                pq.push(x);
            }
        }


        int res = 0;

        while(!pq.empty()){
            vector<int> temp;
            for(int i = 0 ; i < n+1 ; i++){

                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                }

            }


            for(int freq : temp){
                if(freq){
                    pq.push(freq);
                }
            }

            if(pq.empty()){
                res += temp.size();
            }else{
                res += n + 1;
            }
        }

        return res;
    }
};