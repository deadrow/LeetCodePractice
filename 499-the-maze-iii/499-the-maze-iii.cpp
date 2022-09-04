class Solution {
public:
    struct Direction
    {
        int row{0};
        int col{0};
        char direction{0};
    };
    
    struct Node
    {
        int cost{0};
        int row{0};
        int col{0};
        string path{};
    };
    
    vector<Direction>directions{{0,1,'r'},{0,-1,'l'},{1,0,'d'},{-1,0,'u'}};
    string findShortestWay(vector<vector<int>>& maze, vector<int> ball, vector<int> hole) {
        int m = maze.size();
        int n = maze[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        auto compare = [](const Node& a, const Node& b)
        {
            if(a.cost == b.cost)
                return a.path > b.path;
            return a.cost > b.cost;
        };
        
        priority_queue<Node, vector<Node>, decltype(compare)> bfs(compare);
        bfs.push({0, ball[0],ball[1], ""});
        dist[ball[0]][ball[1]] = 0;
        
        while(!bfs.empty())
        {
            auto top = bfs.top();
            int row = top.row;
            int col = top.col;
            string path = top.path;
            bfs.pop();
            
            if(row == hole[0] && col == hole[1])
            {
                return path;
            }
            
            for(auto it : directions)
            {
                int nRow = row;
                int nCol = col;
                
                int cost = 0;
                while(nRow + it.row >= 0 && nRow + it.row < m && nCol+ it.col >=0 && nCol + it.col < n && maze[nRow+ it.row][nCol+ it.col] == 0)
                {
                    nRow += it.row;
                    nCol += it.col;
                    cost++;
                    
                    if(nRow == hole[0] && nCol == hole[1])
                    {
                        break;
                    }
                }

                if((nRow != row || nCol != col) && dist[row][col] + cost <= dist[nRow][nCol])
                {
                    dist[nRow][nCol] = dist[row][col] + cost;
                    bfs.push({dist[nRow][nCol], nRow, nCol, path+it.direction});
                }  
            }
        }
        
        return "impossible";
    }
};