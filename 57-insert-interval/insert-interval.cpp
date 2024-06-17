class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()) return {newInterval};
        auto it = upper_bound(intervals.begin(), intervals.end(), newInterval);
        int idx = it-intervals.begin();
        cout << idx;

        vector<vector<int>> mergeIntervals;
        for(int i=0;i<idx;i++)
            mergeIntervals.push_back(intervals[i]);

        if(!mergeIntervals.empty() and newInterval[0] <= mergeIntervals.back()[1]) {
            mergeIntervals.back()[1] = max(mergeIntervals.back()[1], newInterval[1]);
        } else {
            mergeIntervals.push_back(newInterval);
        }

        // merge
        for(int i=idx;i<intervals.size();i++){
            if(intervals[i][0] <= mergeIntervals.back()[1]) {
                mergeIntervals.back()[1] = max(mergeIntervals.back()[1], intervals[i][1]);
            } else
                mergeIntervals.push_back(intervals[i]);
        }

        return mergeIntervals;
    }
};