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
        set<pair<int,int>, greater<pair<int,int>>> st;
        
        for(auto it : userToTweets[userId])
            st.insert(it);
        
        for(auto it : followerMap[userId])
        {
            for(auto it1 : userToTweets[it])
                st.insert(it1);
        }
        
        vector<int> ret;
        if(st.size() < 10)
        {
            for(auto it : st)
                ret.push_back(it.second);
        }
        else
        {
            int counter = 10;
            auto it = st.begin();
            while(counter--)
            {
                int val = it->second;
                ret.push_back(val);
                *it++;
            }
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