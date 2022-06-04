class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        priority_queue<pair<int, int>> pq;
        
        int i = 0;
        int j = 0;
        while(j < nums.size())
        {
            pq.push({nums[j], j});
            
            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k)
            {
                while(pq.top().second < i)
                    pq.pop();
                
                ret.push_back(pq.top().first);
                
                i++;
                j++;
            }
        }
        
        return ret;
    }
};