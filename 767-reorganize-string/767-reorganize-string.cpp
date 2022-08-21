class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>dict;
        
        for(auto it : s)
            dict[it]++;
        
        priority_queue<pair<int,char>>pq;
        for(auto it : dict)
            pq.push({it.second, it.first});
        
        string ret;
        int start = 0;
        while(!pq.empty())
        {
            pair<int,char> top1 = pq.top();
            pq.pop();
            
            if(pq.empty() && top1.first >= 2)
                return "";
            
            ret += top1.second;
            top1.first--;
            
            if(pq.empty())
                return ret;
            
            pair<int,char> top2 = pq.top();
            pq.pop();
            
            ret += top2.second;
            top2.first--;
            
            if(top1.first)
                pq.push(top1);
            
            if(top2.first)
                pq.push(top2);
        }
        
        return ret;
    }
};