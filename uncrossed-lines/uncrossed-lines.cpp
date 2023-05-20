class Solution {
public:
    vector<vector<int>>memo;
    int dp(vector<int>& nums1, vector<int>& nums2, int i, int j)
    {
        int m = nums1.size();
        int n = nums2.size();
        if(i >= m || j >= n)
            return 0;

        if(memo[i][j] != -1)
            return memo[i][j];

        int take = 0;
        if(nums1[i] == nums2[j])
            take = 1 + dp(nums1, nums2, i+1, j+1);
        
        int leave = max(dp(nums1, nums2, i+1, j), dp(nums1, nums2, i, j+1));
        return memo[i][j] = max(take, leave);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memo.resize(nums1.size(), vector<int>(nums2.size(), -1));
        return dp(nums1, nums2, 0, 0);
    }
};