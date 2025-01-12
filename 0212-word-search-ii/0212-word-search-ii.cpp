class Solution {
public:

    struct trie{
        bool endWord ;
        trie* child[26];
        string word;

        trie(){
            endWord = false;
            for(int i = 0 ; i < 26 ; i++){
                child[i] = nullptr;
            }
            word = "";
        }
    };

    void insert(trie* root , string word){

        trie* crawl = root;

        for(auto ch : word){
            
            int idx = ch-'a';
            if(crawl->child[idx] == nullptr){
                crawl->child[idx] = new trie();
            }
            crawl = crawl->child[idx];
        }

        crawl->endWord = true;
        crawl->word = word;
    }
    vector<int> rowChange = {1,-1,0,0};
    vector<int> colChange = {0,0,1,-1};

    void searchWord(int i,int j ,vector<vector<char>>& board,trie* root,vector<string>& res){

        if(i >= board.size() || i < 0 || j < 0 || j >= board[0].size() || board[i][j] == '$') return ;
        
        char ch = board[i][j] ;

        if(root->child[ch-'a'] == nullptr) return;

        root = root->child[ch-'a'];

        if(root->endWord){
           root->endWord = false;
            res.push_back(root->word);
        }

        char temp = board[i][j];
        board[i][j] = '$';

        for(int k = 0 ; k < 4 ; k++){
            int newRow = i + rowChange[k];
            int newCol = j + colChange[k];

            searchWord(newRow,newCol,board,root,res);

        }
        board[i][j] = temp;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            int n= board.size();
            int m = board[0].size();

            vector<string> res;
            trie* root = new trie();

            for(auto &word: words){
                insert(root,word);
            }


            for(int i = 0 ; i < n ; i++){

                for(int j = 0 ; j < m ; j++){

                    char ch = board[i][j];

                    if(root->child[ch-'a'] != nullptr){
                        searchWord(i,j,board,root,res);
                    }

                }

            }



        return res;
    }
};