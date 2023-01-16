class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty())
            return {newInterval};
        
        int start = upper_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        
        vector<vector<int>> result(intervals.begin(), intervals.begin()+start);
        
        if(result.empty() || newInterval[0] > result.back()[1])
            result.push_back(newInterval);
        else
            result.back()[1] = max(newInterval[1], result.back()[1]);
        
        for(int i=start;i<intervals.size();i++)
        {
            if(intervals[i][0] <= result.back()[1])
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            else
                result.push_back(intervals[i]);
        }
        
        return result;
    }
};