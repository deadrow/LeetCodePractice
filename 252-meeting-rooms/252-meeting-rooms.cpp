class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return true;
        
        auto compare = [](const vector<int>& a, const vector<int>& b)
        {
            return a[1] < b[1];
        };
        
        sort(intervals.begin(), intervals.end(), compare);
        
        int count = 1;
        int i = 0;
        for(int j=1;j<n;j++)
        {
            if(intervals[j][0] >= intervals[i][1])
            {
                count++;
                i = j;
            }
        }
        
        return count == n;
    }
};