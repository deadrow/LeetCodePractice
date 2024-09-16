class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal=0;
        int count=1;
        int maxCount=1;
        for(auto it : nums){
            if(it > maxVal){
                maxVal = it;
                count = 1;
                maxCount = 1;
            } else if(it == maxVal){
                count++;
                maxCount = max(maxCount, count);
            } else count=0;
        }
        return maxCount;
    }
};