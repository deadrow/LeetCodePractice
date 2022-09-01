class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n));
        
        auto compare = [](const vector<int>& a, const vector<int>& b)
        {
            return a[0] > b[0];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> bfs(compare);
        bfs.push({0,start[0],start[1]});

		while(!bfs.empty())
		{
			auto top = bfs.top();
			bfs.pop();
			
			int curDistance = top[0];
			int row = top[1];
			int col = top[2];
			
			if(visited[row][col])
				continue;
			
			visited[row][col] = true;

			if(row == destination[0] && col == destination[1])
				return curDistance;

			for(auto it : directions)
			{
				int nRow = row;
				int nCol = col;
				
				int steps = 0;
				while(nRow+it.first >= 0 && nRow+it.first < m && nCol+it.second >=0 && nCol+it.second < n && maze[nRow+it.first][nCol+it.second] == 0)
				{
					steps++;
					nRow += it.first;
					nCol += it.second;
				}
				
				// ball hit the wall.
				bfs.push({curDistance+steps, nRow, nCol});
			}
		}
        
        return -1;
    }
};