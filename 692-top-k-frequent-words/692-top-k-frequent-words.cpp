class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int>dict;
        
        for(auto it : words)
            dict[it]++;
        
        auto compare = [](const pair<int, string>& a, const pair<int, string>& b)
        {
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        };
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(compare)>pq(compare);
        
        for(auto it : dict)
            pq.push({it.second, it.first});
        
        vector<string> ret;
        while(!pq.empty() && k--)
        {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        
        return ret;
    }
};