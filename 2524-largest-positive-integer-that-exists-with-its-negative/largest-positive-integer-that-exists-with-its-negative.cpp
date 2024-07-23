class Solution {
public:
    int findMaxK1(vector<int>& nums) {
        unordered_set<int>mp;
        int maxNum = INT_MIN;
        for(auto it : nums){
            if(mp.count(-it))
                maxNum = max(maxNum, abs(it));
            mp.insert(it);
        }

        return maxNum==INT_MIN ? -1 : maxNum;
    }
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int low=0,high=nums.size()-1;
        int maxNum = INT_MIN;
        while(low<=high){
            int sum = nums[low]+nums[high];
            if(sum==0){
                maxNum = max(maxNum, abs(nums[low]));
                low++,high--;
            } else if(sum<0)low++;
            else high--;
        }
        return maxNum==INT_MIN ? -1 : maxNum;
    }
};