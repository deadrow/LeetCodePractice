class Solution {
public:
    void setZeroes1(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>rows, cols;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]== 0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        // rows
        for(auto it : rows){
            for(int i=0;i<n;i++)
                matrix[it][i]=0;
        }

        // cols
        for(auto it : cols){
            for(int i=0;i<m;i++)
                matrix[i][it]=0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool isRow = false, isCol=false;

        for(int i=0;i<n;i++){
            if(matrix[0][i]==0)
                isRow=true;
        }

        for(int i=0;i<m;i++){
            if(matrix[i][0]==0)
                isCol=true;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]== 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[0][j]== 0 or matrix[i][0]==0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(isRow){
            for(int i=0;i<n;i++){
                matrix[0][i]=0;
            }
        }

        if(isCol){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};