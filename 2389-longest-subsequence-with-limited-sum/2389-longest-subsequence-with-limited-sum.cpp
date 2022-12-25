class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
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