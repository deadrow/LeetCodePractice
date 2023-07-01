class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ret;

        auto cmp = [&](const pair<int,int>& a, const pair<int,int>& b)
        {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        set<pair<int,int>> visited;
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)>pq(cmp);
        pq.push({0,0});

        while(ret.size() < k && !pq.empty())
        {
            int i = pq.top().first;
            int j = pq.top().second;
            pq.pop();

            if(visited.count({i, j}))
                continue;

            ret.push_back({nums1[i], nums2[j]});
            visited.insert({i, j});
            
            if(i+1 < nums1.size())
                pq.push({i+1, j});

            if(j+1 < nums2.size())
                pq.push({i, j+1});
        }

        return ret;
    }
};