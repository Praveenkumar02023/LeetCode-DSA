class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
      int n = queries.size();

      vector<int> res(n,-1);

       priority_queue<int> pq;

       for(int it = 0 ; it < n ; it++){

        int x = queries[it][0];
        int y = queries[it][1];

        int dis = abs(x) + abs(y);

        pq.push(dis);

        if(pq.size() == k){
            res[it] = pq.top();
        }
        else if(pq.size() > k){
            pq.pop();
            res[it] = pq.top();
        }

       }

       return res;
    }
};