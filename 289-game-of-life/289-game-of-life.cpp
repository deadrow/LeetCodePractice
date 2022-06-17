class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,1},{1,-1}};

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n));
        // ans = board;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == 0)
                {
                    int countLives = 0;
                    for(auto it : directions)
                    {
                        int nRow = i + it.first;
                        int nCol = j + it.second;
                        if(nRow >=0 && nRow < m && nCol >=0 && nCol < n)
                        {
                            if(board[nRow][nCol] == 1)
                                countLives++;
                        }
                    }
                    
                    if(countLives == 3)
                        ans[i][j] = 1;
                }
                else
                {
                    int countLives = 0;
                    for(auto it : directions)
                    {
                        int nRow = i + it.first;
                        int nCol = j + it.second;
                        if(nRow >=0 && nRow < m && nCol >=0 && nCol < n)
                        {
                            if(board[nRow][nCol] == 1)
                                countLives++;
                        }
                    }
                    
                    if(countLives < 2 || countLives > 3)
                        ans[i][j] = 0;
                    else if(countLives == 2 or countLives == 3)
                        ans[i][j] = 1;
                }
            }
        }
        
        board = ans;
    }
};