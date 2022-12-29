class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        auto compare1 = [](const vector<int>& a, const vector<int>& b)
        {
            return a[1] > b[1];  
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare1)>pq(compare1);
        
        auto compare2 = [](const vector<int>& a, const vector<int>& b)
        {
            if(a[2] != b[2])
                return a[2] > b[2];
            return a[0] > b[0];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare2)>waitingTasks(compare2);
        
        for(int i=0;i<tasks.size();i++)
            pq.push({i, tasks[i][0], tasks[i][1]});
        
        vector<int> result;
        long time = pq.top()[1];
        
        while(!pq.empty() || !waitingTasks.empty())
        {
            while(!pq.empty() && pq.top()[1] <= time)
            {
                waitingTasks.push(pq.top());
                pq.pop();
            }
            
            if(!waitingTasks.empty())
            {
                time = time + waitingTasks.top()[2];
                result.push_back(waitingTasks.top()[0]);
                waitingTasks.pop();
            }
            else
                time = pq.top()[1];
        }
        
        return result;
    }
};