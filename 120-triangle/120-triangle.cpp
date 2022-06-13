class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        
        if(m == 1)
            return triangle[0][0];
        
        int n = triangle[m-1].size();
//         vector<vector<int>>dp(m, vector<int>(n));
        
//         dp[0][0] = triangle[0][0];
//         dp[0][1] = triangle[0][0];
        
        int j=0;
        for(int i=1;i<m;i++)
        {
            int size = triangle[i].size();
            for(int j=0;j<size;j++)
            {
                if(j == 0)
                    triangle[i][j] = triangle[i-1][j] + triangle[i][j];
                else if(j == size-1)
                    triangle[i][j] = triangle[i-1][j-1] + triangle[i][j];
                else
                    triangle[i][j] = min(triangle[i-1][j-1], triangle[i-1][j]) + triangle[i][j];
            }
        }
        
        return *min_element(triangle[m-1].begin(), triangle[m-1].end());
    }
};