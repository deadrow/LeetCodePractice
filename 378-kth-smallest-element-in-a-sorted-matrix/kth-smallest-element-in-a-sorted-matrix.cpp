class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp = [&](const pair<int,int>& a, const pair<int,int>& b) {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)>pq(cmp);

        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++)
            pq.push({i, 0});

        while(!pq.empty() && --k) {
            auto cur = pq.top();
            pq.pop();
            if(cur.second+1 < n)
                pq.push({cur.first, cur.second+1});
        }

        return matrix[pq.top().first][pq.top().second];
    }
};