class Solution {
public:
    unordered_set<int>mp;
    vector<int>memo;
    int dp(int day, int lastDay, vector<int>& costs){
        if(day>lastDay) return 0;
        if(memo[day] != -1) return memo[day];
        int sum = 0;
        if(mp.count(day)){
            sum = min({costs[0]+dp(day+1, lastDay, costs), costs[1]+dp(day+7, lastDay, costs), costs[2]+dp(day+30, lastDay, costs)});
        } else
            sum = dp(day+1, lastDay, costs);
        return memo[day]=sum;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(auto it : days) mp.insert(it);
        memo.resize(days.back()+1, -1);
        return dp(1, days.back(), costs);
    }
};