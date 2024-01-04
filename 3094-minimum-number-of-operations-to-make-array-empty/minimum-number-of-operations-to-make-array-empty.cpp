class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>dict;
        for(auto& it : nums)
            dict[it]++;

        int ops = 0;
        for(auto& it : dict)
        {
            if(it.second == 1)
                return -1;
            else if(it.second % 3 == 0)
                ops += it.second/3;
            else
                ops += it.second/3+1;
        }

        return ops;
    }
};