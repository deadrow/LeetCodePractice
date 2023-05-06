class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int MOD = 1000000007;
        int n = nums.size();

        // Two pointer approach
        // Find i and j such that nums[i]+nums[j] <= target
        // Then the subsequences would be 2pow(j-i) because
        // we are only taking min and max. In between all the
        // numbers would be part of that powerset
        
        // precalculate otherwise it is giving TLE
        vector<int>pow(n);
        pow[0] = 1;
        for(int i=1;i<n;i++)
        {
            pow[i] = pow[i-1]*2 % MOD;
        }

        int i=0;
        int j= n-1;
        int ans = 0;
        while(i<=j)
        {
            if(nums[i]+nums[j] <= target)
            {
                ans = (ans+ pow[j-i]) % MOD;
                i++;
            }
            else
                j--;
        }

        return ans;
    }
};