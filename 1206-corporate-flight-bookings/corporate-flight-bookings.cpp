class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        map<int,int>sweep{{0,0}};

        for(auto it : bookings)
        {
            sweep[it[0]] += it[2];
            sweep[it[1]+1] -= it[2];
        }

        int curSum = 0;
        for(auto& it : sweep)
        {
            curSum += it.second;
            it.second = curSum;
        }

        vector<int>ret;
        for(int i=1;i<=n;i++)
        {
            auto itr = prev(sweep.upper_bound(i));
            ret.push_back(itr->second);
        }

        return ret; 
    }
};