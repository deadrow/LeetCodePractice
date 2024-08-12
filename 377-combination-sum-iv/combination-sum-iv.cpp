class Solution {
public:
    vector<int>memo;
    int dp(vector<int>& nums, int target){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(memo[target] != -1) return memo[target];
        int count=0;
        for(int i=0;i<nums.size();i++){
            count += dp(nums, target-nums[i]);
        }
        return memo[target]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memo.resize(target+1, -1);
        return dp(nums, target);
    }
};