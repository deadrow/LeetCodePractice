class Solution {
public:
    struct Node
    {
        int i{0};
        int j{0};
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        auto compare = [&](const Node& a, const Node& b)
        {
            return (nums1[a.i] + nums2[a.j]) > (nums1[b.i] + nums2[b.j]);
        };
        
        priority_queue<Node, vector<Node>, decltype(compare)>pq(compare);

        int m = nums1.size();
        int n = nums2.size();
        
        pq.push({0, 0});
        
        set<pair<int,int>>visited;
        vector<vector<int>> ret;
        while(!pq.empty() && ret.size() < k)
        {
            int i = pq.top().i;
            int j = pq.top().j;
            pq.pop();
            
            if(visited.find({i,j}) != visited.end())
                continue;
            
            visited.insert({i,j});
            ret.push_back({nums1[i], nums2[j]});
            
            if(i+1 < m)
                pq.push({i+1,j});
            
            if(j+1 < n)
                pq.push({i, j+1});
        }
        
        return ret;
    }
};