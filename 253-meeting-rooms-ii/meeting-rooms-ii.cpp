class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
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
};