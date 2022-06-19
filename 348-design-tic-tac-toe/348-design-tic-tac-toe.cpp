class TicTacToe {
public:
    vector<vector<int>>board;
    int n;
    TicTacToe(int n) {
        board.resize(n, vector<int>(n,-1));
        this->n = n;
    }
    
    bool checkWin(int row, int col, int player)
    {
        // check row
        bool winning = true;
        for(int i=0;i<n;i++)
        {
            if(board[row][i] != player)
            {
                winning = false;
                break;
            }     
        }
        
        if(winning)
            return true;
        
        winning = true;
        
        // check column
        for(int i=0;i<n;i++)
        {
            if(board[i][col] != player)
            {
                winning = false;
                break;
            } 
        }
        
        if(winning)
            return true;
        
        winning = true;
        
        // check diags
        for(int i=0;i<n;i++)
        {
            if(board[i][i] != player)
            {
                winning = false;
                break;
            } 
        }
        
        if(winning)
            return true;
        
        winning = true;
        // check anti diags
        for(int i=0;i<n;i++)
        {
            if(board[i][n-i-1] != player)
            {
                winning = false;
                break;
            } 
        }
        
        if(winning)
            return true;
        
        return false;
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;
        
        // check win
        if(checkWin(row, col, player))
            return player;
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */