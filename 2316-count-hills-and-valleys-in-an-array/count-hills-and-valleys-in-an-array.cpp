class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int hill = 0;
        int valley = 0;
        int prev=nums[0];
        vector<int>compact;
        compact.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i] != prev)
                compact.push_back(nums[i]);
            prev = nums[i];
        }

        for(int i=1;i<compact.size()-1;i++){
            if(compact[i-1] < compact[i] and compact[i] > compact[i+1])
                hill++;
            else if(compact[i-1] > compact[i] and compact[i] < compact[i+1])
                valley++;
        }
        return hill+valley;
    }
};