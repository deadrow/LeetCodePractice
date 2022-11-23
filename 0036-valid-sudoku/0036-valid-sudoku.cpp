class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> row[9];
        unordered_set<int> col[9];
        unordered_set<int> box[9];
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                int val = board[i][j] -'0';
                if(board[i][j] == '.')
                   continue;
                   
                if(row[i].find(val) != row[i].end())
                    return false;
                
                row[i].insert(val);
                
                if(col[j].find(val) != col[j].end())
                    return false;
                
                col[j].insert(val);
                
                int index = (i/3)*3 + j/3;
                if(box[index].find(val) != box[index].end())
                    return false;
                
                box[index].insert(val);
            }
        }
        
        return true;
    }
};