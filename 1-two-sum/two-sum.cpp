class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>dict;
        for(int i=0;i<nums.size();i++){
            if(dict.find(target-nums[i]) != dict.end()) return {i, dict[target-nums[i]]};
            dict[nums[i]]=i;
        }

        return {0,0};
    }
};