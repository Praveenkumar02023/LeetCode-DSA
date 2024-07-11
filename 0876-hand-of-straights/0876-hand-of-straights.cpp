class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if(hand.size() % k != 0) return false;
 
        unordered_map<int,int> mp;
        priority_queue<int,vector<int>,greater<int>> pq;

        for(int x : hand){
            if(!mp[x]){
                pq.push(x);
            }

            mp[x]++;
        }

        while(!pq.empty()){
            
            int first = pq.top();
            
            for(int i = 0 ; i < k ; i++){

                if(!pq.empty()){
                    int temp = first + i;
                    if(mp[temp] == 0) return false;

                    mp[temp]--;
                   

            
                    if(mp[temp] == 0){
                        if(temp != pq.top()) return false;

                        pq.pop();
                    }
                   
                }else return false;
            }

            if(pq.empty()) break;
        }


        return true;



   
    }
};