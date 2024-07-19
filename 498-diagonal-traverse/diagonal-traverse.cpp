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
            if(it.first%2!=0){
                for(auto v : it.second)
                    ret.push_back(v);
            } else {
                for(auto v=it.second.rbegin();v!=it.second.rend();v++)
                    ret.push_back(*v);
            }
        }
        return ret;
    }
};