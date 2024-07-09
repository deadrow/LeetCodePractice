class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        // int idx = lower_bound(intervals.begin(), intervals.end(), toBeRemoved)-intervals.begin();
        
        vector<vector<int>>ret;
        for(auto it : intervals){
            if(it[1] < toBeRemoved[0] or it[0] > toBeRemoved[1])
                ret.push_back(it);
            else {
                int low = min(it[0], toBeRemoved[0]);
                int high = max(it[1], toBeRemoved[1]);
                if(low != toBeRemoved[0])
                    ret.push_back({low, toBeRemoved[0]});
                if(high != toBeRemoved[1])
                    ret.push_back({toBeRemoved[1], high});
            }
        }
        return ret;
    }
};