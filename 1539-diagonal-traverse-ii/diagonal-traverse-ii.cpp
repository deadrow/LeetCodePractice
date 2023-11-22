class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>>diags;

        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                diags[i+j].push_back(nums[i][j]);
            }
        }

        int cur = 0;
        vector<int>ret;
        while(diags.find(cur) != diags.end())
        {
            for(auto it=diags[cur].rbegin();it!= diags[cur].rend();++it)
                ret.push_back(*it);

            cur++;
        }
        return ret;
    }
};