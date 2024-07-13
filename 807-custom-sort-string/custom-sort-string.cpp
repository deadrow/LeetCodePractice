class Solution {
public:
    string customSortString1(string order, string s) {
        unordered_map<char, int>dict;
        for(int i=0;i<order.size();i++) dict[order[i]] = i;
        int counter = s.size()-1;
        sort(s.begin(), s.end(), [&](char a, char b){
            int idx_a = dict.count(a) ? dict[a] : INT_MIN;
            int idx_b = dict.count(b) ? dict[b] : INT_MIN;
            return idx_a < idx_b;
        });
        return s;
    }

    string customSortString(string order, string s) {
        unordered_map<char, int>dict;
        for(auto it : s) dict[it]++;
        string ret;
        for(auto it : order){
            if(dict.count(it)){
                ret += string(dict[it], it);
                dict.erase(it);
            }  
        }

        for(auto it : dict)
            ret += string(it.second, it.first);
        return ret;
    }
};