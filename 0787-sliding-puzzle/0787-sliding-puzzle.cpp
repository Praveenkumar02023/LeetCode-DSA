class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string curBoard = "";
        for(int i = 0 ; i < 2 ; i++){
            for(int j = 0 ; j < 3 ; j++){

                curBoard += to_string(board[i][j]);

            }
        }

        string ans = "123450";
        queue<string> que;
        que.push(curBoard);

        unordered_set<string> set;
        set.insert(curBoard);

        unordered_map<int,vector<int>> mp;

        mp[0] = {1,3};
        mp[1] = {0,2,4};
        mp[2] = {1,5};
        mp[3] = {0,4};
        mp[4] = {1,3,5};
        mp[5] = {2,4};

        int level = 0;
        while(!que.empty()){

            int n = que.size();

            while(n--){

                string curr = que.front();
                que.pop();
                
                if(curr == ans) return level;

                int indexOfZero = curr.find('0');

                for(int sideIdx : mp[indexOfZero]){

                    string newState = curr;
                    swap(newState[indexOfZero],newState[sideIdx]);

                    if(set.find(newState) == set.end()){
                        que.push(newState);
                        set.insert(newState);
                    }
                }
            }

            level++;
        }

        return -1;
    }
};