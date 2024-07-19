class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> ret;
        for(auto it : mp){
            if(it.first%2!=0)
                ret.insert(ret.end(), it.second.begin(), it.second.end());
            else
                ret.insert(ret.end(), it.second.rbegin(), it.second.rend());
        }
        return ret;
    }
};