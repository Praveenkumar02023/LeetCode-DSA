class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> left(arr.size()), right(arr.size());

        stack<pair<int, int>> mp1, mp2;

        // finding Last smaller element to the left
        for (int i = 0; i < arr.size(); i++) {
            int cnt = 1;
            while (!mp1.empty() && mp1.top().first > arr[i]) {
                cnt += mp1.top().second;
                mp1.pop();
            }

            mp1.push({arr[i], cnt});
            left[i] = cnt;
        }

        // for next smaller element to right
        for (int i = arr.size() - 1; i >= 0; i--) {
            int cnt = 1;
            while (!mp2.empty() && mp2.top().first >= arr[i]) {
                cnt += mp2.top().second;
                mp2.pop();
            }

            mp2.push({arr[i], cnt});
            right[i] = cnt;
        }

        int ans = 0;
        int mx = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            ans = (ans + (arr[i] * ((long long)left[i] * right[i] % mx)) % mx) %
                  mx;
        }

        return ans;
    }
};