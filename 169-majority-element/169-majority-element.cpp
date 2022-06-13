class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0;
        int candidate = -1;
        
        // boyer moore algorithm
        for(auto it : nums)
        {
            if(count == 0)
                candidate = it;
            
            count += (candidate == it) ? 1 : -1;
        }
        
        return candidate;
    }
};