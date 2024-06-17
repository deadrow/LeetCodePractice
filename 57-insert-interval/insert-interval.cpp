class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // simplest solution is to push newInterval to intervals
        // sort it and then it becomes simple merge intervals

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        // merge
        vector<vector<int>> ret;
        for(int i=0;i<intervals.size();i++){
            if(ret.empty() or ret.back()[1] < intervals[i][0])
                ret.push_back(intervals[i]);
            else
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
        }
        return ret;
    }
};