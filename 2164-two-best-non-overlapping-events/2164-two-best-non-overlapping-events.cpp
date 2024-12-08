class Solution {
public:
    int t[100001][3];
    int binarySearch(vector<vector<int>>& events , int endIndex){

        int l = 0 , r = events.size() - 1;
        int result = events.size();
        while(l <= r){
            int mid = l + (r-l)/2;

            if(events[mid][0] > endIndex){
                result = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }

        }

        return result;

    }

    int solve(vector<vector<int>>& events , int i , int count , int n){

            if(count >= 2 || i >= n){
                return 0;
            }

            if(t[i][count] != -1) return t[i][count];

            int nextIndex = binarySearch(events,events[i][1]);
            int take = events[i][2] + solve(events,nextIndex,count + 1 , n);

            int notTake = solve(events,i+1,count,n);

            return t[i][count] = max(take , notTake);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n = events.size();
        memset(t,-1,sizeof(t));

        int cnt = 0;

        return solve(events,0,cnt,n);

    }
};