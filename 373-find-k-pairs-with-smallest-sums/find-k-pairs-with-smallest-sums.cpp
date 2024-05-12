class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&](const pair<int,int>& a, const pair<int,int>& b) {
            return nums1[a.first]+nums2[a.second] > nums1[b.first]+nums2[b.second];
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)>pq(cmp);
        pq.push({0,0});

        set<pair<int,int>>visited;
        vector<vector<int>>ret;

        while(ret.size() < k && !pq.empty()) {
            auto [i, j] = pq.top();
            pq.pop();

            if(visited.count({i,j}))
                continue;

            visited.insert({i,j});
            ret.push_back({nums1[i], nums2[j]});

            if(i+1 < nums1.size())
                pq.push({i+1, j});        

            if(j+1 < nums2.size())
                pq.push({i, j+1});            
        }

        return ret;
    }
};