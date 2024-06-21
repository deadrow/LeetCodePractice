class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>stringToFreq;
        map<int, set<string>, greater<int>>dict;
        for(auto it : words) {
            if(stringToFreq.count(it)) {
                int oldFreq = stringToFreq[it];
                dict[oldFreq].erase(it);
                if(dict[oldFreq].empty())
                    dict.erase(oldFreq);
                dict[oldFreq+1].insert(it);
                stringToFreq[it] = oldFreq+1;
            } else {
                dict[1].insert(it);
                stringToFreq[it] = 1;
            }
        }

        vector<string>ret;
        for(auto it : dict) {
            for(auto it1 : it.second)
            if(k-- > 0) {
                ret.push_back(it1);
            }
        }
        return ret;
    }
};