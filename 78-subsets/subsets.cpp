class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        for(int i= pow(2, nums.size())-1;i>=0;i--){
            vector<int> cur;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j))
                    cur.push_back(nums[j]);
            }
            ret.push_back(cur);
        }
        return ret;
    }
};