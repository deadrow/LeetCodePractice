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
                    // Logic if arr = [1,5,7,9] and target=20
                    // if i=0, low=1 and high=3 and sum < target
                    // it means all the elements less than high
                    // would also be less than target. So count
                    // them
                    count += high-low;
                    low++;
                }
                else high--;
            }
        }
        return count;
    }
};