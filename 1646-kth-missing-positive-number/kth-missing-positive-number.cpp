class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<bool>nums(2000);
        for(auto it : arr){
            nums[it] = true;
        }
        int i=1;
        for(;i<nums.size();i++) {
            if(!nums[i]) k--;
            if(k == 0) break;
        }

        return i;
    }
};