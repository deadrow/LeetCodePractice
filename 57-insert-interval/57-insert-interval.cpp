class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        int i = 0;
        int n = intervals.size();
        
        // Find all intervals less than new interval intersection
        while(i < n && newInterval[0] > intervals[i][0])
        {
            res.push_back(intervals[i++]);
        }
        
        // check if res is empty or new interval is completely bigger
        // in that case just add it to end
        if(res.empty() || res.back()[1] < newInterval[0])
        {
            res.push_back(newInterval);
        }
        else
        {
            // else find out last one from result and find the 
            // max of ending index
            res.back()[1] = max(res.back()[1], newInterval[1]);
        }

        // This step is exactly same as merge intervals
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