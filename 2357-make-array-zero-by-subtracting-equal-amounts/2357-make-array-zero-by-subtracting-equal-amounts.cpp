class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> unique(nums.begin(), nums.end());
        return unique.size() - unique.count(0);
    }
};