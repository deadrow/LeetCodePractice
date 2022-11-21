class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n));
        
        queue<pair<int,int>>bfs;
        
        bfs.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
            
        int steps = 0;
        while(!bfs.empty())
        {
            int size = bfs.size();
            for(int i=0;i<size;i++)
            {
                auto cur = bfs.front();
                bfs.pop();
                
                if(!(cur.first == entrance[0] && cur.second == entrance[1]) && (cur.first == 0 || cur.first == m-1 || cur.second == 0 || cur.second == n-1))
                    return steps;
                
                // visited[cur.first][cur.second] = true;
                for(auto it : directions)
                {
                    int nRow = cur.first + it.first;
                    int nCol = cur.second + it.second;
                    if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && maze[nRow][nCol] != '+' &&  !visited[nRow][nCol])
                    {
                        bfs.push({nRow, nCol});
                        visited[nRow][nCol] = true;
                    }
                }
                
            }
            
            steps++;
        }
        
        return -1;
    }
};