class Solution {
public:
    // bitmasking solution
    vector<vector<int>> subsets1(vector<int>& nums) {
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

    vector<vector<int>> ret;
    void backtrack(vector<int>& nums, int cur_i, int k, vector<int>&cur){
        if(cur.size() > k) return;
        if(cur.size()==k) {
            ret.push_back(cur);
            return;
        }
        for(int i=cur_i;i<nums.size();i++){
            cur.push_back(nums[i]);
            backtrack(nums, i+1, k, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        for(int i=0;i<=nums.size();i++){
            vector<int>cur;
            backtrack(nums, 0, i, cur);
        }
        return ret;
    }
};