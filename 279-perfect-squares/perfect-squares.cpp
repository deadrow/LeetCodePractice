class Solution {
public:
    vector<int>memo;
    vector<int>nums;
    int dp(int target){
        if(target == 0) return 0;
        if(memo[target] != -1) return memo[target];
        int count = INT_MAX;
        for(auto& it : nums){
            if(target-it >=0) {
                count = min(count, 1+dp(target-it));
            }
        }
        return memo[target]=count;
    }
    int numSquares(int n) {
        for(int i=1;i*i<=n;i++)
            nums.push_back(i*i);
        memo.resize(n+1, -1);
        return dp(n);
    }
};