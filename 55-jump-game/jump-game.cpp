class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachableIdx = n-1;
        for(int i=n-2;i>=0;i--) {
            if(i+nums[i] >= reachableIdx)
                reachableIdx = i;
        }
        return reachableIdx == 0;
    }
};