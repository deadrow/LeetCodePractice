class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        int low = 0;
        int high = n-1;
        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            int k = queries[i][0];
            int trim = queries[i][1];
            
            priority_queue<pair<string,int>>pq;
            
            for(int j=0;j<n;j++)
            {
                int numSize = nums[j].size();
                
                if(pq.size() != k)
                    pq.push({nums[j].substr(numSize-trim),j});
                else
                {
                    if(pq.top().first >= nums[j].substr(numSize-trim))
                    {
                        pq.push({nums[j].substr(numSize-trim),j});
                        pq.pop();
                    }
                }
            }

            ans.push_back(pq.top().second);
        }
        
        return ans;
    }
};