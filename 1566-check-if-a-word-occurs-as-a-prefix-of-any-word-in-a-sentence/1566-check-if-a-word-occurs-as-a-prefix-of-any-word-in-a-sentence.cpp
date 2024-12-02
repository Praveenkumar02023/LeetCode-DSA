class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int searchWordSize = searchWord.size();
        int n = sentence.size();

        bool checkWord = false;
    

        string tempWord = sentence.substr(0,searchWordSize);
        if(tempWord == searchWord) return 1;
        int wordCnt = 1;

        for(int i = 1 ; i < n ; i++){
            if(sentence[i-1] ==  ' '){
                checkWord = true;
                wordCnt += 1;
            }
            if(checkWord){
                string tempWord = sentence.substr(i,searchWordSize);
                if(tempWord == searchWord){
                   return wordCnt;
                } 
                checkWord = false;
            }
            
        }

        return -1 ;
    }
};