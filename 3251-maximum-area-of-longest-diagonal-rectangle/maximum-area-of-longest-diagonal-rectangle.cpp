class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        sort(dimensions.begin(), dimensions.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0]*a[0]+a[1]*a[1] == b[0]*b[0]+b[1]*b[1])
                return a[0]*a[1] > b[0]*b[1];
            return a[0]*a[0]+a[1]*a[1] > b[0]*b[0]+b[1]*b[1];
        });
        return dimensions[0][0]*dimensions[0][1];
    }
};