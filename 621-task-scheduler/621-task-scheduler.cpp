class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0)
            return tasks.size();
        
        unordered_map<char, int>hash;
        
        for(auto it : tasks)
            hash[it]++;
        
        priority_queue<pair<int,char>> pq;
        queue<pair<int,char>> q;
        
        for(auto it : hash)
        {
            pq.push({it.second, it.first});
        }
        
        int counter = 0;
        
        while(!pq.empty())
        {
            pair<int,char> top = pq.top();
            pq.pop();
            
            counter++;
            
            top.first--;
            
            hash[top.second]--;
            if(hash[top.second] == 0)
                hash.erase(top.second);
            
            if(hash.size() == 0)
                break;
            
            q.push(top);
            
            int k = n+1;
            
            if(q.size() < k && pq.empty()) // Insert idle and count
            {
                int diff = k-q.size();
                while(diff--)
                {
                    counter++;
                    k--;
                }
            }
            
            if(q.size() >= k)
            {
                while(!q.empty())
                {
                    if(q.front().first)
                        pq.push(q.front());
                    q.pop();
                }
            }
        }
        
        return counter;
    }
};