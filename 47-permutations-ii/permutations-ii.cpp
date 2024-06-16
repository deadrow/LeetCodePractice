class Solution {
public:
    vector<vector<int>> res;
    
    void backtrack(vector<int>& nums, int cur){
        if(cur == nums.size()){
            res.push_back(nums);
            return;
        }

        // Keep track of duplicates in current recursion stack
        unordered_set<int>dict; 
        for(int i=cur;i<nums.size();i++){
            if(dict.find(nums[i]) != dict.end()) continue;
            dict.insert(nums[i]);
            swap(nums[i], nums[cur]);
            backtrack(nums, cur+1);
            swap(nums[i], nums[cur]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};