class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        set<int>ret;
        for(auto it : nums){
            mp[it]++;
            if(mp[it] > nums.size()/3) ret.insert(it);
        }
        return vector<int>(ret.begin(), ret.end());
    }
};