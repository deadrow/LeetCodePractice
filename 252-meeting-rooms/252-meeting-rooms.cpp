class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return true;

        sort(intervals.begin(), intervals.end());
        
        int count = 1;
        int i = 0;
        for(int j=0;j<n-1;j++)
        {
            if(intervals[j][1] > intervals[j+1][0])
                return false;
        }
        
        return true;
    }
};