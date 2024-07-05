class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]>0 and nums[i]<=n and nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
        }

        for(int i=0;i<n;i++){
            if(i+1 != nums[i]) return i+1;
        }
        return n+1;
    }
};