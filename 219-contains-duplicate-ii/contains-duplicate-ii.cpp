class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>dict;
        for(int i=0;i<nums.size();i++){
            if(dict.count(nums[i])){
                for(auto& it : dict[nums[i]]){
                    if(abs(i-it) <= k) return true;
                }
            }
            dict[nums[i]].push_back(i);
        }
        return false;
    }
};