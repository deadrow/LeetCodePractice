class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k == 0 || k == 1)
            return s;

        int hash[26] = {0};
        
        for(auto it : s)
            hash[it-'a']++;
        
        priority_queue<pair<int,int>> pq;
        queue<pair<int,int>> q;
        
        for(int i=0;i<26;i++)
        {
            if(hash[i] != 0)
                pq.push({hash[i], i});
        }
        
        string ret;
        while(!pq.empty())
        {
            pair<int,int> top = pq.top();
            pq.pop();
            
            ret += top.second + 'a';
            
            top.first--;
            q.push(top);
            
            if(q.size() >= k)
            {
                if(q.front().first)
                    pq.push(q.front());
                q.pop();
            }
        }
        
        return ret.size() == s.size() ? ret : "";
    }
};