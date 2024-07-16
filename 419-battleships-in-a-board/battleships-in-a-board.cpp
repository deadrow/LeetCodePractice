class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<char>>& board, int row, int col, int m, int n){
        board[row][col] = '.';
        for(auto it : directions){
            int nRow = it.first + row;
            int nCol = it.second + col;
            if(nRow>=0 and nRow<m and nCol>=0 and nCol<n and board[nRow][nCol] == 'X') {
                dfs(board, nRow, nCol, m, n);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int islands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'X'){
                    islands++;
                    dfs(board, i, j, m, n);
                }
            }
        }
        return islands;
    }
};