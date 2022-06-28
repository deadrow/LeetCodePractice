class Solution {
public:
    vector<pair<int, int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n));
        
        auto compare = [](const vector<int>& a, const vector<int>& b)
        {
            return a[0] < b[0];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);
        
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        int min_weight = INT_MAX;
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            
            int weight = top[0];
            int row = top[1];
            int col = top[2];
            
            min_weight = min(weight, min_weight);
            
            if(row == m-1 && col == n-1)
            {
                return min_weight;
            }
            
            visited[row][col] = true;
            
            for(auto it : directions)
            {
                int nRow = row + it.first;
                int nCol = col + it.second;
                if(nRow >=0 && nRow < m && nCol >= 0 && nCol < n && !visited[nRow][nCol])
                {
                    pq.push({grid[nRow][nCol], nRow, nCol});
                }
            }
        }
        
        return 0;
    }
};