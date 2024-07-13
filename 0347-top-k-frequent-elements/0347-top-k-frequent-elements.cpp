class Solution {
public:
    

    vector<int> topKFrequent(vector<int>& nums, int k) {
     vector<int> res;

     unordered_map<int,int> mp;

     for(int x : nums) mp[x]++;

     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

     for(auto it : mp){
        pq.push(make_pair(it.second,it.first));

        if(pq.size() > k){
            pq.pop();
        }
     }

     while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
     }

     return res;

    }
};