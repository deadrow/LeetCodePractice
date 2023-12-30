class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int>sweep;
        for(auto it : flowers)
        {
            sweep[it[0]] += 1;
            sweep[it[1]+1] -= 1;
        }

        int curSum = 0;
        for(auto& it : sweep)
        {
            curSum += it.second;
            it.second = curSum;
        }

        vector<int>ret;
        for(auto it : people)
        {
            auto itr = sweep.upper_bound(it);
            if(itr == sweep.begin())
                ret.push_back(0);
            else{
                auto prev_itr = prev(itr);
                ret.push_back(prev_itr->second);
            }
        }

        return ret;
    }
};