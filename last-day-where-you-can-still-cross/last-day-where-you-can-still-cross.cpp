class Solution {
public:
    int r = 0;
    int c = 0;
    vector<pair<int,int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    bool canCross(vector<vector<int>>& cells, int right)
    {
        vector<vector<int>> grid(r, vector<int>(c));

        for(int i=0; i<=right; i++)
            grid[cells[i][0]-1][cells[i][1]-1] = 1;

        queue<pair<int, int>>bfs;
        for(int i=0;i<c;i++)
        {
            if(grid[0][i] == 0)
            {
                bfs.push({0, i});
                grid[0][i] = -1;
            }

        }

        while(!bfs.empty())
        {
            int curRow = bfs.front().first;
            int curCol = bfs.front().second;
            bfs.pop();

            if(curRow == r-1)
                return true;

            for(auto it : directions)
            {
                int nRow = curRow + it.first;
                int nCol = curCol + it.second;
                if(nRow >=0 && nRow < r && nCol >=0 && nCol < c && grid[nRow][nCol] == 0)
                {
                    grid[nRow][nCol] = -1;
                    bfs.push({nRow, nCol});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        r = row;
        c = col;

        int n = cells.size();
        int left = 1;
        int right = n;
        while(left < right)
        {
            int mid = left + (right-left)/2;
            
            if(!canCross(cells, mid))
                right = mid;
            else
                left = mid+1;
        }

        return left;
    }
};