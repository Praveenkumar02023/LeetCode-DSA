class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        int n = s.size();
        vector<int> diffArray(n);

        for (auto query : shifts) {

            int start = query[0];
            int end = query[1];
            int direction = query[2];

            if (direction == 1)
                diffArray[start] += 1;
            else
                diffArray[start] -= 1;

            if (end + 1 < n) {
                if (direction == 1)
                    diffArray[end + 1] -= 1;
                else
                    diffArray[end + 1] += 1;
            }
        }
        // for (int i = 0; i < n; i++) {
        //     cout << diffArray[i] << " ";
        // }
        // cout << endl;

        for (int i = 1; i < n; i++) {
            diffArray[i] += diffArray[i - 1];
        }

        // for (int i = 0; i < n; i++) {
        //     cout << diffArray[i] << " ";
        // }
        // cout << endl;

        for (int i = 0; i < n; i++) {

            int ch = s[i] - 'a';

            ch += diffArray[i];

            ch = ((ch % 26) + 26) % 26;

            s[i] = ch + 'a';
        }

        return s;
    }
};