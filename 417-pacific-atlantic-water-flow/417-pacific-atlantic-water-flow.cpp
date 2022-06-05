class Solution {
public:
    vector<vector<int>> heights;
    int rows;
    int cols;
    vector<pair<int,int>> directions{{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    vector<vector<bool>> bfs(queue<pair<int,int>>& inQueue)
    {
        vector<vector<bool>> ret(rows, vector<bool>(cols));
        
        // check if we reach able to reach any edge from this point
        while(!inQueue.empty())
        {
            int row = inQueue.front().first;
            int col = inQueue.front().second;
            inQueue.pop();
            
            ret[row][col] = true;
            for(auto it : directions)
            {
                int nRow = row + it.first;
                int nCol = col + it.second;
                
                if(nRow >=0 && nRow < rows && nCol >=0 && nCol < cols && !ret[nRow][nCol])
                {
                    if(heights[nRow][nCol] >= heights[row][col])
                        inQueue.push({nRow, nCol});
                }
            }
        }
        
        return ret;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        this->rows = m;
        this->cols = n;
        
        heights.resize(m, vector<int>(n));
        this->heights = heights;
                
        queue<pair<int,int>> pacificQueue;
        queue<pair<int,int>> atlanticQueue;
        
        // first row
        for(int i=0;i<n;i++)
        {
            pacificQueue.push({0,i});
            atlanticQueue.push({m-1,i});
        }
        
        // first column
        for(int i=0;i<m;i++)
        {
            pacificQueue.push({i,0});
            atlanticQueue.push({i, n-1});
        }
        
        vector<vector<bool>> pacific = bfs(pacificQueue);
        vector<vector<bool>> atlantic = bfs(atlanticQueue);
        
        
        vector<vector<int>> ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};