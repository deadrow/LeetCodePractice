class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // 1 1 3 3 4 5 7 8 9
        // 2 2 2 4 5 5 5 5 7 7 8 8 9 9 10 11 12 12
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for(int i=0;i<nums.size()-2;i+=3){
            if(nums[i+2]-nums[i] <= k)
                ret.push_back({nums[i], nums[i+1], nums[i+2]});
            else return {};
        }
        return ret;
    }
};