class Solution {
public:
    // Greedy
    bool canJump1(vector<int>& nums) {
        int n = nums.size();
        int reachableIdx = n-1;
        for(int i=n-2;i>=0;i--) {
            if(i+nums[i] >= reachableIdx)
                reachableIdx = i;
        }
        return reachableIdx == 0;
    }
    // dp with memo
    vector<int>memo;
    bool dp(vector<int>& nums, int start){
        if(start>=nums.size()-1) return true;
        if(memo[start] != -1) return memo[start];
        for(int i=start+1;i<=start+nums[start];i++)
            if(dp(nums, i)) return memo[start]=true;
        return memo[start]=false;
    }
    bool canJump(vector<int>& nums) {
        memo.resize(nums.size()+1, -1);
        return dp(nums, 0);
    }
};