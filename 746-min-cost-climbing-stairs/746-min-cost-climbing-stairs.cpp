class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
            
        int one_back = 0;
        int two_back = 0;
            
        for(int i=2;i<=n;i++)
        {
            int cur = min(one_back + cost[i-1], two_back + cost[i-2]);
            two_back = one_back;
            one_back = cur;
        }

        return one_back;
    }
};