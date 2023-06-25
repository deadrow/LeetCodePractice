class Solution {
public:
    vector<vector<int>>memo;
    int MOD = 1000000007;
    int dp(vector<int>& locations, int start, int finish, int fuel)
    {
        if(fuel < 0)
            return 0;

        if(memo[start][fuel] != -1)
            return memo[start][fuel];

        int ans = 0;
        if(start == finish)
            ans += 1;

        for(int j=0;j<locations.size();j++)
        {
            if(start != j)
            {
                int ret = dp(locations, j, finish, fuel - abs(locations[start] - locations[j])) % MOD;
                ans += ret;
                ans %= MOD;
            }
        }

        return memo[start][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memo.resize(locations.size(), vector<int>(fuel+1,-1));
        return dp(locations, start, finish, fuel);
    }
};