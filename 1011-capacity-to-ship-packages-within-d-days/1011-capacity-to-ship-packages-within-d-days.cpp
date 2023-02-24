class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        // binary search template from 
        // https://leetcode.com/discuss/general-discussion/786126/Python-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems
        
        auto feasible = [=](int capacity){
            int curCapacity = 0;
            int curDays = 1;
            for(int i=0;i<weights.size();i++)
            {
                curCapacity += weights[i];
                if(curCapacity > capacity)
                {
                    curCapacity = weights[i];
                    curDays += 1;
                    if(curDays > days)
                        return false;
                }
            }
            
            return true;
        };
        
		// Find out max weight. This is the least capacity we would want
		int left = *max_element(weights.begin(), weights.end());
		
		// Find out total weight. This is the max weight we would want if days is 1
		int right = accumulate(weights.begin(), weights.end(), 0);
        
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