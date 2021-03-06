class NumMatrix {
public:
    vector<vector<int>>prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        prefix.resize(m, vector<int>(n));
        for(int i=0;i<m;i++)
        {
            prefix[i][0] = matrix[i][0];
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                prefix[i][j] = prefix[i][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int prefixSum = 0;
        int diffSum = 0;
        for(int i=row1;i<=row2;i++)
            prefixSum += prefix[i][col2];
        
        if(col1 > 0)
        {
            for(int i=row1;i<=row2;i++)
                diffSum += prefix[i][col1-1];
        }

        return prefixSum - diffSum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */