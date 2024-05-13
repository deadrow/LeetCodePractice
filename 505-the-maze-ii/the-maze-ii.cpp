class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();

        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push({start[0], start[1], 0});

        set<pair<int,int>>visited;
        // visited.insert({start[0], start[1]});

        while(!pq.empty()) {
            int row = pq.top()[0];
            int col = pq.top()[1];
            int dist = pq.top()[2];
            pq.pop();

            if(row == destination[0] and col == destination[1]) return dist;

            if(visited.count({row, col}))
                continue;

            visited.insert({row,col});

            for(auto& [x,y] : directions) {
                int nRow = row + x;
                int nCol = col + y;

                int steps = 1;
                while(nRow >= 0 && nRow < m && nCol >=0 && nCol < n && maze[nRow][nCol] == 0) {
                    // keep rolling
                    nRow += x;
                    nCol += y;
                    steps++;
                }

                // we hit a wall. So move one step back
                nRow -= x;
                nCol -= y;
                steps -= 1;

                pq.push({nRow, nCol, dist+steps});
            }
        }

        return -1;
    }
};