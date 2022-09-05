class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int>dict;
        
        for(auto it : words)
            dict[it]++;
        
        auto compare = [](const pair<int, string>& a, const pair<int, string>& b)
        {
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        };
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(compare)>pq(compare);
        
        for(auto it : dict)
        {
            pq.push({it.second, it.first});
            if(pq.size() > k)
                pq.pop();
        }
            
        
        vector<string> ret;
        while(!pq.empty())
        {
            ret.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};