class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // binary search template from 
        // https://leetcode.com/discuss/general-discussion/786126/Python-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems
        
		auto feasible = [=](int day){
			int flowers = 0;
			int groups = 0;
			for(auto it : bloomDay)
			{
				if(it <= day)
					flowers++;
				else
				{
					groups += flowers / k;
					flowers = 0;
				}
			}
			
            groups += flowers / k;
			return groups >= m;
		};
        
        if((long)m*k > bloomDay.size())
            return -1;
        
		int left = *min_element(bloomDay.begin(), bloomDay.end());
		
		int right = *max_element(bloomDay.begin(), bloomDay.end());
        
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