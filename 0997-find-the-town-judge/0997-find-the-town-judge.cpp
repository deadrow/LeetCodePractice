class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1)
            return 1;
        
        unordered_map<int, unordered_set<int>>dict;
        
        for(auto it : trust)
            dict[it[1]].insert(it[0]);
        
        int counts = 0;
        
        int ret = -1;
        for(auto it : dict)
        {
            // check if any dict has n-1 size
            // it should be only one dict
            if(it.second.size() == n-1)
            {
                for(auto it1 : it.second)
                {
                    if(dict.find(it1) != dict.end())
                    {
                        if(dict[it1].find(it.first) != dict[it1].end())
                            return -1;
                    }  
                }
                
                ret = it.first;
            }
        }
        
        return ret;
    }
};