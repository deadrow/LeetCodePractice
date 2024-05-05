class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>dict;
        for(auto& it : s) dict[it]++;

        priority_queue<pair<int, char>, vector<pair<int,char>>>pq;
        for(auto& it : dict) pq.push({it.second, it.first});

        string ret;
        while(!pq.empty()) {
            ret += string(pq.top().first, pq.top().second);
            pq.pop();
        }

        return ret;
    }
};