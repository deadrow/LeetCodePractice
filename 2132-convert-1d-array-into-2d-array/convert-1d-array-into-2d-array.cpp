class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n != original.size()) return {};
        vector<vector<int>> ret(m, vector<int>(n));
        int j=0,k=0;
        for(int i=0;i<original.size();i++){
            if(k==n){
                j++;
                k=0;
            }
            ret[j][k] = original[i];
            k++;
        }
        return ret;
    }
};