class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int>rows(m);
        vector<int>cols(n);

        // rows
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j])
                {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] and rows[i]==1 and cols[j]==1)
                    cnt++;
            }
        }
        
        return cnt;
    }
};