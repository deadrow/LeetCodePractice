class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<>> pq;
        
        pq.push(intervals[0][1]);
        
        for(int j=1;j<n;j++)
        {
            if(intervals[j][0] >= pq.top())
                pq.pop();
            
            pq.push(intervals[j][1]);
        }
        
        return pq.size();
    }
};