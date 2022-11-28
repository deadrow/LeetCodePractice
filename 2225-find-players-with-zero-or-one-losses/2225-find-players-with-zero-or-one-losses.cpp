class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> winners;
        map<int, int> losers;
        
        for(auto it : matches)
        {
            winners[it[0]]++;
            
            losers[it[1]]++;
        }
        
        vector<vector<int>>ret;
        
        vector<int>wins;
        for(auto it : winners)
        {
            if(losers.find(it.first) == losers.end())
                wins.push_back(it.first);
        }
        
        ret.push_back(wins);
        
        vector<int>loses;
        for(auto it : losers)
        {
            if(it.second == 1)
                loses.push_back(it.first);
        }
        
        ret.push_back(loses);
        return ret;
    }
};