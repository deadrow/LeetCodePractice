class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> set;
        for(auto it : nums)
        {
            if(set.find(it) != set.end())
                return true;
            set.insert(it);
        }
        
        return false;
    }
};