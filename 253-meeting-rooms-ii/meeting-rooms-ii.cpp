class Solution {
public:
    // Line sweep
    int minMeetingRooms1(vector<vector<int>>& intervals) {
        map<int,int> sweep;
        for(auto it : intervals) {
            sweep[it[0]] += 1;
            sweep[it[1]] -= 1;
        }

        int curMax = 0;
        int curSum = 0;
        for(auto it : sweep) {
            curSum += it.second;
            curMax = max(curMax, curSum);
        }

        return curMax;
    }

    // Heap solution
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort the array by start time
        sort(intervals.begin(), intervals.end());

        // Use min heap. Idea is to find out the earliest 
        // ending meeting room.
        priority_queue<int, vector<int>, greater<int>>pq;

        for(const auto& it : intervals) {
            if(!pq.empty() and it[0] >= pq.top())
                pq.pop();

            pq.push(it[1]);
        }

        return pq.size();
    }
};