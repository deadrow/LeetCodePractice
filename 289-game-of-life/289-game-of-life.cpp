class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,1},{1,-1}};

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        // vector<vector<int>> ans(m, vector<int>(n));
        // ans = board;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int countLives = 0;
                for(auto it : directions)
                {
                    int nRow = i + it.first;
                    int nCol = j + it.second;
                    if(nRow >=0 && nRow < m && nCol >=0 && nCol < n)
                    {
                        if(board[nRow][nCol] == 1 || board[nRow][nCol] == -1)
                            countLives++;
                    }
                }
                
                if(board[i][j] == 1 && (countLives < 2 || countLives > 3))
                    board[i][j] = -1;
                
                if(board[i][j] == 0 && countLives == 3)
                    board[i][j] = 2;
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] > 0)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
};