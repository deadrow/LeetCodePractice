class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        
        int count = 0;
        int i = 0;
        while(startFuel < target)
        {
            while(i < stations.size() && startFuel >= stations[i][0])
                pq.push(stations[i++][1]);
            
            if(pq.empty())
                return -1;
            
            startFuel += pq.top();
            pq.pop();
            count++;
        }
        
        return count++;
    }
};