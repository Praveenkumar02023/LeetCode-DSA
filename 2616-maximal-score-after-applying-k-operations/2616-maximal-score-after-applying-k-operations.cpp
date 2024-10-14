class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;

        priority_queue<int> pq;

        for(auto x : nums){
            pq.push(x);
        }

        while(k > 0){
            int top = pq.top();
            pq.pop();
            ans += top;
            cout<<top<<endl;
            pq.push(ceil(top/3.0));
            k--;
        }

        return ans;

    }
};