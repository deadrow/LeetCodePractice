class Twitter {
public:
    unordered_map<int, unordered_set<int>>following;
    vector<pair<int,int>>tweets;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ret;
        for(int i=tweets.size()-1;i>=0;i--) {
            auto& [user, tweet] = tweets[i];
            if(user == userId or following[userId].contains(user)) {
                ret.push_back(tweet);
                if(ret.size() == 10)
                    break;
            }
        }

        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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