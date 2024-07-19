class Solution {
public:
    vector<vector<int>>memo;
    bool dp(vector<int>& nums, int cur_i, int target){
        if(target < 0) return false;
        if(target == 0) return true;
        if(memo[cur_i][target] != -1) return memo[cur_i][target];
        for(int i=cur_i;i<nums.size();i++){
            if(dp(nums, i+1, target-nums[i])) return memo[cur_i][target]=true;
        }
        return memo[cur_i][target]=false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum % 2 != 0) return false;
        memo.resize(nums.size()+1, vector<int>(sum/2+1, -1));
        return dp(nums, 0, sum/2);
    }
};