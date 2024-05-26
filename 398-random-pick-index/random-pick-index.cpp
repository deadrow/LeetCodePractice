class Solution {
public:
    unordered_map<int,vector<int>>dict;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            dict[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int curSize = dict[target].size();
        return dict[target][rand()%curSize];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */