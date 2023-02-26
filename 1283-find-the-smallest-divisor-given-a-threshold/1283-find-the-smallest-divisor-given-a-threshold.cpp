class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // binary search template from 
        // https://leetcode.com/discuss/general-discussion/786126/Python-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems
        
        auto feasible = [=](int divisor){
            int curThreshold = 0;
            for(auto it : nums)
            {
                curThreshold += ceil((float)it/divisor);
            }
            
            return curThreshold <= threshold;
        };
        

		int left = 1;
		int right = *max_element(nums.begin(), nums.end());
        
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(feasible(mid))
                right = mid;
            else
                left = mid+1;
        }
        
        return left;
    }
};