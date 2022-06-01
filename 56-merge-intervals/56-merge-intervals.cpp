class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        sort(intervals.begin(), intervals.end());
        
        res.push_back(intervals[0]);
        for(int j=1;j<intervals.size();j++)
        {
            if(intervals[j][0] <= res.back()[1])
            {
                res.back()[1] = max(intervals[j][1],res.back()[1]);
            }
            else
                res.push_back(intervals[j]);
        }
        
        return res;
    }
};