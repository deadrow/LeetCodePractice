class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26);
        for(auto it : s)
            freq[it-'a']++;
        
        priority_queue<int> pq;
        for(auto it : freq)
        {
            if(it != 0)
                pq.push(it);
        }
        
        int ans = 0;

        while(pq.size() > 1)
        {
            int top = pq.top();
            pq.pop();
            
            if(pq.top() == top)
            {
                ans++;
                if(top-1>0)
                    pq.push(top-1);
            }
        }
        
        return ans;
    }
};