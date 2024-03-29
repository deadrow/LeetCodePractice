class Twitter {
public:
    int tweetTimeStamp = 1;
    unordered_map<int, vector<pair<int,int>>> userToTweets;
    unordered_map<int,set<int>> followerMap;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userToTweets[userId].push_back({tweetTimeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        
        // own tweets
        for(auto it : userToTweets[userId])
            pq.push(it);
        
        // followers tweets
        for(auto it : followerMap[userId])
        {
            for(auto it1 : userToTweets[it])
                pq.push(it1);
        }
        
        vector<int> ret;
        int counter = 10;
        while(counter--)
        {
            if(pq.empty())
                break;

            ret.push_back(pq.top().second);
            pq.pop();
        }
        
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        followerMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = followerMap[followerId].find(followeeId);
        if(it != followerMap[followerId].end())
            followerMap[followerId].erase(it);
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