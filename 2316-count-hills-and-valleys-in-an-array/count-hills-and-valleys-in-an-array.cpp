class Solution {
public:
    int countHillValley1(vector<int>& nums) {
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
    
    // https://leetcode.com/problems/count-hills-and-valleys-in-an-array/solutions/1879182/two-pointers/
    // Votrubac solution
    int countHillValley(vector<int>& nums) {
        int ret=0;
        for(int i=1,j=0;i<nums.size()-1;i++){
            if((nums[j] < nums[i] and nums[i] > nums[i+1]) or
                (nums[j] > nums[i] and nums[i] < nums[i+1])
            ) {
                ret++;
                j=i;
            }
        }
        return ret;
    }

};