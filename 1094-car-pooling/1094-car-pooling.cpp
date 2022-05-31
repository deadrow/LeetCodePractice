class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        
        auto compare = [](const vector<int>& a, const vector<int>& b)
        {
            return a[1] < b[1];  
        };
        
        sort(trips.begin(), trips.end(), compare);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        pq.push({trips[0][2], trips[0][0]});
        int cur_capacity = trips[0][0];
        if(cur_capacity > capacity)
            return false;
        
        for(int i=1;i<n;i++)
        {
            while(!pq.empty() && trips[i][1] >= pq.top().first)
            {
                cur_capacity -= pq.top().second;
                pq.pop();
            }
                
            pq.push({trips[i][2], trips[i][0]});
            cur_capacity += trips[i][0];
            if(cur_capacity > capacity)
                return false;
        }
        
        return true;
    }
};