class Solution {
public:
    struct Direction {
        int r{0};
        int c{0};
        char dir{0};
    };

    struct Node {
        int r{0};
        int c{0};
        int dist{0};
        string path{};
    };

    vector<Direction>directions{{0,1,'r'},{0,-1,'l'},{1,0,'d'},{-1,0,'u'}};
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size();
        int n = maze[0].size();

        auto cmp = [](const Node& a, const Node& b) {
            if(a.dist == b.dist)
                return a.path > b.path;
            return a.dist > b.dist;
        };

        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
        pq.push({ball[0], ball[1], 0, ""});

        set<pair<int,int>>visited;

        while(!pq.empty()) {
            int row = pq.top().r;
            int col = pq.top().c;
            int dist = pq.top().dist;
            string path = pq.top().path;
            pq.pop();

            if(visited.count({row, col}))
                continue;
            
            if(row == hole[0] and col == hole[1]) {
                return path;
            }

            visited.insert({row,col});

            for(auto& it : directions) {
                int steps = 0;
                int nRow = row;
                int nCol = col;
                while(nRow+it.r >= 0 && nRow+it.r < m && nCol+it.c >=0 && nCol+it.c < n && maze[nRow+it.r][nCol+it.c] == 0) {
                    // keep rolling
                    nRow += it.r;
                    nCol += it.c;
                    steps++;
                    
                    if(nRow == hole[0] and nCol == hole[1]) {
                        break;
                    }
                }

                pq.push({nRow, nCol, dist+steps, path+it.dir});
            }
        }

        return "impossible";
    }
};