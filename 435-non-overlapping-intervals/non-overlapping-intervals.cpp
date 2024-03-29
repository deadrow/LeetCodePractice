class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        int end = intervals[0][1];

        int count = 1;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0] >= end)
            {
                end = intervals[i][1];
                count++;
            }
        }

        return intervals.size()-count;
    }
};