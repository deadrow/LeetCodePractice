class Solution {
public:
    vector<pair<int, int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        int ans = max(grid[0][0], grid[m-1][n-1]);
        pq.push({ans, 0, 0});

        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            
            int weight = top[0];
            int row = top[1];
            int col = top[2];
            
            if(row == m-1 && col == n-1)
            {
                return ans;
            }
            
            ans = max(ans, weight);
            
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