class Solution {
public:
    bool dfs(vector<vector<char>>& board, int row, int col, int m, int n, string& word, int cur_i)
    {
        if(cur_i == word.size())
            return true;
        
        if(row < 0 || row >= m || col < 0 || col >= n || word[cur_i] != board[row][col])
            return false;
        
        board[row][col] = '.';
        bool exists = (dfs(board, row+1, col, m, n, word, cur_i+1) ||
                      dfs(board, row-1, col, m, n, word, cur_i+1) ||
                      dfs(board, row, col+1, m, n, word, cur_i+1) ||
                      dfs(board, row, col-1, m, n, word, cur_i+1));
        board[row][col] = word[cur_i];
        return exists;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == word[0] && dfs(board, i, j, m, n, word, 0))
                    return true;
            }
        }
        
        return false;
    }
};