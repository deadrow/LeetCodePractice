class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int maxFreq=0;
        int freq=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == maxVal){
                freq++;
                maxFreq = max(maxFreq, freq);
            }
            else freq=0;
        }
        return maxFreq;
    }
};