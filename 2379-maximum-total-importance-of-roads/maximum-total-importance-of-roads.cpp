class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>indeg(n);
        for(auto it : roads){
            indeg[it[0]]++;
            indeg[it[1]]++;
        }
        priority_queue<vector<int>>pq;
        for(int i=0;i<n;i++)
            pq.push({indeg[i], i});
        
        int val=n;
        while(!pq.empty()){
            auto cur = pq.top();pq.pop();
            indeg[cur[1]] = val--;
        }

        long long ret=0;
        for(auto it : roads){
            ret += indeg[it[0]] + indeg[it[1]];
        }
        return ret;
    }
};