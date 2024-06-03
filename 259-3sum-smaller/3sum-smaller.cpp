class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
                int n = nums.size();
        sort(nums.begin(), nums.end());

        int count = 0;
        for(int i=0;i<n;i++){
            int low = i+1;
            int high = n-1;
            while(low<high) {
                int sum = nums[i]+nums[low]+nums[high];
                if(sum < target) {
                    count += high-low;
                    low++;
                }
                else high--;
            }
        }
        return count;
    }
};