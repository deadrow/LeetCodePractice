class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        
        for(auto it : nums)
        {
            if(it <= firstMin)
                firstMin = it;
            else if(it <= secondMin)
                secondMin = it;
            else
                return true;
        }
        
        return false;
    }
};