class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>last;
        long maxSum=0;
        long curSum=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(last.count(nums[i])){
                // if element is found remove all the element till last occurance as
                // they won't be included in the window
                while(j<=last[nums[i]]){
                    last.erase(nums[j]);
                    curSum -= nums[j];
                    j++;
                }
            }

            last[nums[i]] = i;
            curSum += nums[i];
            if(i-j+1 == k)
                maxSum = max(curSum, maxSum);
            else if(i-j+1 > k){
                curSum -= nums[j];
                last.erase(nums[j]);
                maxSum = max(curSum, maxSum);
                j++;
            }
        }
        return maxSum;
    }
};