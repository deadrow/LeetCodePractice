class Solution1 {
public:
    unordered_map<int,vector<int>>dict;
    Solution1(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            dict[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int curSize = dict[target].size();
        return dict[target][rand()%curSize];
    }
};

// reservoir sampling
class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int count = 0;
        int pickIdx = 0;
        for(int i=0;i<nums.size();i++) {
            if(target == nums[i]) {
                count++;
                if(rand()%(count) == count-1)
                    pickIdx = i;
            }
        }
        return pickIdx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */