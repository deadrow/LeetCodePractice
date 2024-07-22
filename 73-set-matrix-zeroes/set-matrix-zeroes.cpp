class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
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
};