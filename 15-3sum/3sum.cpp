class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for(int i=0;i<nums.size()-2;i++){
            if(i==0 or nums[i-1]!= nums[i]){
                int low=i+1,high=nums.size()-1;
                while(low<high){
                    int sum = nums[i]+nums[low]+nums[high];
                    if(sum==0){
                        ret.push_back({nums[i], nums[low++], nums[high--]});
                        while(low<high and nums[low-1]==nums[low])low++;
                    } else if(sum<0)low++;
                    else high--;
                }
            }
        }
        return ret;
    }
};