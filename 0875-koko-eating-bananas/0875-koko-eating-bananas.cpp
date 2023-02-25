class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // binary search template from 
        // https://leetcode.com/discuss/general-discussion/786126/Python-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems
        
		auto feasible = [=](int capacity){
			int days = 0;
			for(auto it : piles)
			{
				if(it <= capacity)
					days += 1;
				else
					days += ceil((double)it/capacity);
                
                if(days > h)
                    return false;
			}
			
			return true;
		};
        
		int left = 1;
		int right = *max_element(piles.begin(), piles.end());
        
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