class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        int i = 0;
        int n = intervals.size();
        
        while(i < n && newInterval[0] > intervals[i][0])
        {
            res.push_back(intervals[i++]);
        }
        
        if(res.empty() || res.back()[1] < newInterval[0])
        {
            res.push_back(newInterval);
        }
        else
        {
            res.back()[1] = max(res.back()[1], newInterval[1]);
        }

        for(;i<n;i++)
        {
            if(intervals[i][0] <= res.back()[1])
            {
                res.back()[1] = max(intervals[i][1],res.back()[1]);
            }
            else
                res.push_back(intervals[i]);  
        }
        
        return res;
    }
};