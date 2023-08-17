class Solution {
public:
    vector<pair<int,int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int,int>> bfs;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] == 0)
                    bfs.push({i,j});
            }
        }

        vector<vector<bool>> visited(m, vector<bool>(n));

        int steps = 1;
        while(!bfs.empty())
        {
            int size = bfs.size();
            for(int i=0;i<size;i++)
            {
                int row = bfs.front().first;
                int col = bfs.front().second;
                bfs.pop();

                for(auto it : directions)
                {
                    int nRow = row + it.first;
                    int nCol = col + it.second;

                    if(nRow >=0 && nRow < m && nCol >=0 && nCol < n && mat[nRow][nCol] != 0 && !visited[nRow][nCol])
                    {
                        mat[nRow][nCol] = steps;
                        visited[nRow][nCol] = true;
                        bfs.push({nRow, nCol});
                    }
                }
            }

            steps++;
        }

        return mat;
    }
};