class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

     int n = words.size();
     vector<int> pre(n);

    if(isVowel(words[0][0]) && isVowel(words[0][words[0].size()-1])){
        pre[0] = 1;
    }

     for(int i = 1 ; i < n ;i++){
            pre[i] = pre[i-1];
            char first = words[i][0];
            char last = words[i].back();
            pre[i] += (isVowel(first) && isVowel(last));    
     }

    //  for(int i = 0 ; i < n ; i++){
    //     cout<<pre[i]<<endl;
    //  }
     vector<int> res;
    for(auto query : queries){
        int first = query[0];
        int last = query[1];

        if(first == 0){
            res.push_back(pre[last]);
        }else{
            res.push_back(pre[last]-pre[first-1]);
        }

    }
        return res;
    }
};