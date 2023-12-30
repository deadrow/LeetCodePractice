class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int>sweep{{0,0}};
        for(const auto& it : flowers)
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
        for(const auto& it : people)
        {
            auto itr = prev(sweep.upper_bound(it));
            ret.push_back(itr->second);
        }

        return ret;
    }
};