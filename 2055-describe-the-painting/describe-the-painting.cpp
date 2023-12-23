class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long, long long>range;

        for(auto it : segments)
        {
            range[it[0]] += it[2];
            range[it[1]] -= it[2];
        }

        vector<vector<long long>> ret;

        long long idx=0,paint=0;
        for(auto it : range)
        {
            long long prev_paint = paint;
            paint += it.second;
            if(prev_paint > 0)
                ret.push_back({idx, it.first, prev_paint});
            idx = it.first;
        }

        return ret;
    }
};