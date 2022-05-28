class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expected = nums.size()* (nums.size()+1)/2;
        
        int actual = accumulate(nums.begin(), nums.end(), 0);
        return expected - actual;
    }
};