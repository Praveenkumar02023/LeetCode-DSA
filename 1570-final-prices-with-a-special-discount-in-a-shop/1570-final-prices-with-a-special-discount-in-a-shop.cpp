class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();

        vector<int> res(prices.begin() , prices.end());

        stack<int> st;

        st.push(0);

        for(int i = 1 ; i < n ; i++){


            while(!st.empty() && prices[i] <= prices[st.top()]){
                res[st.top()] = prices[st.top()] - prices[i];
                st.pop();
            }

            st.push(i);
        }

        return res;    

    }
};
