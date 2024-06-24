class Solution {
public:

    long long Nmin(vector<int> & n){
        vector<int> left(n.size()),right(n.size()) ;
         long long minSum = 0;
        stack<pair<int,int>> st1,st2;

        for(int i = 0 ; i < n.size() ; i++){
            int cnt = 1;
            while(!st1.empty() && st1.top().first > n[i] ){
                cnt += st1.top().second;
                st1.pop();
            }
            st1.push({n[i],cnt});
            left[i] = cnt;
        } 

        for(int i = n.size()-1 ; i >= 0 ; i--){

            int cnt = 1;
            while(!st2.empty() && st2.top().first >= n[i]){
                cnt += st2.top().second;
                st2.pop();
            }

            st2.push({n[i],cnt});
            right[i] = cnt;
        }

        for(int i = 0 ; i < n.size() ; i++ ){
            minSum += (n[i] * (long long)(left[i] * right[i]));
        }

        return minSum;

    }

    long long Nmax(vector<int> & n){
        vector<int> left(n.size()),right(n.size()) ;
         long long maxSum = 0;
        stack<pair<int,int>> st1,st2;

        for(int i = 0 ; i < n.size() ; i++){
            int cnt = 1;
            while(!st1.empty() && st1.top().first < n[i] ){
                cnt += st1.top().second;
                st1.pop();
            }
            st1.push({n[i],cnt});
            left[i] = cnt;
        } 

        for(int i = n.size()-1 ; i >= 0 ; i--){

            int cnt = 1;
            while(!st2.empty() && st2.top().first <= n[i]){
                cnt += st2.top().second;
                st2.pop();
            }

            st2.push({n[i],cnt});
            right[i] = cnt;
        }

        for(int i = 0 ; i < n.size() ; i++ ){
            maxSum += (n[i] * (long long)(left[i] * right[i]));
        }

        return maxSum;

    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
       
        long long minn = Nmin(nums);
        long long maxx = Nmax(nums);

        return maxx-minn;

    }
};