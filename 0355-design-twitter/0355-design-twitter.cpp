class Twitter {
    unordered_map<int,set<int>> follows;
    unordered_map<int,vector<pair<int,int>>> t;
    long long time;

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        t[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;

        for(auto it = t[userId].begin() ; it != t[userId].end() ; it++){
            pq.push(*it);
        }

        for(auto it1 = follows[userId].begin() ; it1 != follows[userId].end() ; it1++){
            int user = *it1;

            for(auto it2 = t[user].begin() ; it2 != t[user].end() ; it2++){
                pq.push(*it2);
            }
        }

        vector<int> res;

        while(!pq.empty()){
            res.push_back(pq.top().second);

            if(res.size() == 10) break;

            pq.pop();
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
             follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */