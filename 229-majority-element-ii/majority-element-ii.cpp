class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ret;
        for(auto it : nums){
            mp[it]++;
            if(mp[it] == nums.size()/3+1) ret.push_back(it);
        }
        return ret;
    }
};