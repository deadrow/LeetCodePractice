class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long counter = 0;
        long ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] != 0)
            {
                ans += counter*(counter+1)/2;
                counter = 0;
            }
            else
                counter++;
        }
        
        ans += counter*(counter+1)/2;
        
        return ans;
    }
};