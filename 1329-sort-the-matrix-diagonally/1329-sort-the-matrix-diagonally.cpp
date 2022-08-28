class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, multiset<int>> dict;
        
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dict[i-j].insert(mat[i][j]);
            }
        }
        
        vector<vector<int>> ret(m, vector<int>(n));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ret[i][j] = *dict[i-j].begin();
                dict[i-j].erase(dict[i-j].begin());
            }
        }
        
        return ret;
    }
};