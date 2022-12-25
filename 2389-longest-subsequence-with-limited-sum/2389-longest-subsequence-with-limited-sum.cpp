class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        vector<int> prefix(nums);
        for(int i=1;i<nums.size();i++)
            prefix[i] = nums[i] + prefix[i-1];
        
        vector<int> result;
        for(auto it : queries)
        {
            auto it1 = upper_bound(prefix.begin(), prefix.end(), it);
            result.push_back(it1-prefix.begin());
        }
        
        return result;
    }
    
    vector<int> answerQueries1(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        vector<int> result;
        for(auto it : queries)
        {
            int curSize = 0;
            int curSum = 0;
            for(auto it1 : nums)
            {
                if(curSum+it1 <= it)
                {
                    curSum += it1;
                    curSize++;
                }
            }
            
            result.push_back(curSize);
        }
        
        return result;
    }
};