class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> pairs;
        
        for(int i=0;i<n;i++)
        {
            pairs.push_back({speed[i], efficiency[i]});
        }
        
        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b)
             {
                 return a.second > b.second;
             });
        
        priority_queue<int, vector<int>, greater<>>pq;
        
        long sum = 0;
        long result = 0;
        for(auto it : pairs)
        {
            pq.push(it.first);
            sum += it.first;
            
            if(pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            
            result = max(result , sum*it.second);
        }
        
        return result % (int)(1e9+7);
    }
};