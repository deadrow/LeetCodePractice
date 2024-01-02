class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>dict;
        for(auto it : nums)
            dict[it]++;
        
        vector<pair<int,int>> v;
        for(auto it : dict)
            v.push_back({it.first, it.second});
        
        sort(v.begin(), v.end(), [&](const auto& x, const auto& y) { return x.second > y.second;});

        int i = 0;
        vector<vector<int>> ret;

        int lim =  v[0].second;
        while(i < lim)
        {
            vector<int> cur;
            for(int j=0;j<v.size();j++)
            {
                if(v[j].second > 0)
                    cur.push_back(v[j].first);
                v[j].second--;
            }
            ret.push_back(cur);
            i++;
        }

        return ret;
    }
};