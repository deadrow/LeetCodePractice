class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int>ret;
        int max = INT_MIN;
        for(int i=n-1;i>=0;i--) {
            if(heights[i] > max) {
                ret.push_back(i);
                max = heights[i];
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};