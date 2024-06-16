class Solution {
public:
    vector<vector<int>> ret;
    vector<int>memo;
    int dp(vector<int>& nums, int target){
        if(target == 0) return 1;

        if(memo[target] != -1) return memo[target];
        int ways=0;
        for(auto it : nums) {
            if(target-it>=0)
                ways += dp(nums, target-it);
        }
        return memo[target]=ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memo.resize(target+1,-1);
        return dp(nums, target);
    }
};