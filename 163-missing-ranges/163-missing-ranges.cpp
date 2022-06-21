class Solution {
public:
    string formatString(int lower, int upper)
    {
        string res;
        if(lower == upper)
        {
            res = to_string(lower);
        }
        else
        {
            res = to_string(lower) + "->" + to_string(upper);
        }
        return res;
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ret;
        int n = nums.size();
        
        if(n == 0)
        {
            ret.push_back(formatString(lower, upper));
            return ret;
        }
  
        if(lower < nums[0])
        {
            ret.push_back(formatString(lower, nums[0]-1));
        }
            
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]+1 == nums[i+1])
                continue;
            
            int start = nums[i]+1;
            int end = nums[i+1]-1;
            ret.push_back(formatString(start, end));
        }
        
        if(upper > nums[n-1])
            ret.push_back(formatString(nums[n-1]+1, upper));
        
        return ret;
    }
};