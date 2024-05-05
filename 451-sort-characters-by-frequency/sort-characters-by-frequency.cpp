class Solution {
public:
    // priority queue + hash map O(nlogn)
    string frequencySort1(string s) {
        map<char,int>dict;
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

    // bucket sort O(n)
    string frequencySort(string s) {
        map<char,int>dict;
        for(auto& it : s) dict[it]++;

        int maxFreq = max_element(dict.begin(), dict.end(), [](auto a, auto b) { return a.second < b.second;})->second;

        vector<char> buckets[maxFreq+1];
        for(auto it : dict) {
            buckets[it.second].push_back(it.first);
        }

        string ret;
        for(int i=maxFreq;i>=1;i--) {
            for(auto it : buckets[i]) {
                for(int j=0; j<i;j++)
                    ret += it;
            }
        }

        return ret;
    }
};