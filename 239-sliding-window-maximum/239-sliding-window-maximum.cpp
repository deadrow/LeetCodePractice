class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        list<int> maxList;
        
        int i = 0;
        int j = 0;
        while(j < nums.size())
        {
            while(!maxList.empty() && (maxList.back() < nums[j]))
                maxList.pop_back();
            
            maxList.push_back(nums[j]);

            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k)
            {
                ret.push_back(maxList.front());
                
                if(!maxList.empty() && maxList.front() == nums[i])
                    maxList.pop_front();
                
                i++;
                j++;
            }
        }
        
        return ret;
    }
};