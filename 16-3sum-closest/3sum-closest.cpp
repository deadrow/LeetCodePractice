class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closest = INT_MAX;
        int minSum = 0;
        for(int i=0;i<n;i++){
            int low = i+1;
            int high = n-1;
            while(low<high) {
                int sum = nums[i]+nums[low]+nums[high];
                if(abs(target-sum) <= closest) {
                    minSum = sum;
                    closest = abs(target-sum);
                }
                if(sum == target){
                    low++;
                    high--;
                } 
                else if(sum < target) low++;
                else high--;
            }
        }
        return minSum;
    }
};