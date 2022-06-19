class TicTacToe {
public:
    vector<vector<int>>board;
    int n;
    vector<int>rows;
    vector<int>cols;
    int diagonal{0};
    int antidiagonal{0};
    TicTacToe(int n) {
        board.resize(n, vector<int>(n,-1));
        this->n = n;
        rows.resize(n);
        cols.resize(n);
    }

    int move(int row, int col, int player) {
        int currentPlayer = (player == 1) ? 1 : -1;
        
        rows[row] += currentPlayer;
        cols[col] += currentPlayer;
        
        if(row == col)
            diagonal += currentPlayer;
        
        if(col == n-row-1)
            antidiagonal += currentPlayer;
        
        if(abs(rows[row]) == n || abs(cols[col]) == n || abs(diagonal) == n || abs(antidiagonal) == n)
            return player;
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */