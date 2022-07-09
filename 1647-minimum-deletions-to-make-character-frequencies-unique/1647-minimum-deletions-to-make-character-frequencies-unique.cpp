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
            
        
        int res = 0;
        int prev = pq.top();
        pq.pop();
        
        while(!pq.empty())
        {
            if(pq.top() == prev)
            {
                res++;
                prev = pq.top()-1;
                pq.pop();
            }
            else if(prev < pq.top()) // remaining entry greater than prev
            {
                if(prev == 0)
                {
                    while(!pq.empty())
                    {
                        res += pq.top();
                        pq.pop();
                    }
                }
                else
                {
                    res += abs(prev-pq.top())+1;
                    prev -= 1;
                    pq.pop();
                }

            }
            else
            {
                prev = pq.top();
                pq.pop();
            }
        }
        
        return res;
    }
};