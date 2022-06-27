class Solution {
public:
    vector<pair<int, int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<bool>> visited;
    vector<int> maxPaths;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
    
        vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
        
        costs[0][0] = 0;
        
        queue<pair<int, int>> bfs;
        bfs.push({0,0});
        
        while(!bfs.empty())
        {
            int row = bfs.front().first;
            int col = bfs.front().second;
            bfs.pop();
            
            for(auto it : directions)
            {
                int nRow = row + it.first;
                int nCol = col + it.second;
                
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n)
                {
                    int newCost = max(costs[row][col], abs(heights[nRow][nCol] - heights[row][col]));
                    if(newCost < costs[nRow][nCol])
                    {
                        costs[nRow][nCol] = newCost;
                        bfs.push({nRow, nCol});
                    }
                }
            }
        }
        
        return costs[m-1][n-1];
    }
};