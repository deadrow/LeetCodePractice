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
            int firstCharCount = pq.top().first;
            char firstChar = pq.top().second;
            pq.pop();
            
            if(pq.empty() && firstCharCount >= 2)
                return "";
            
            ret += firstChar;
            firstCharCount--;
            
            if(pq.empty())
                return ret;
            
            int secondCharCount = pq.top().first;
            char secondChar = pq.top().second;
            pq.pop();
            
            ret += secondChar;
            secondCharCount--;
            
            if(firstCharCount)
                pq.push({firstCharCount, firstChar});
            
            if(secondCharCount)
                pq.push({secondCharCount, secondChar});
        }
        
        return ret;
    }
};