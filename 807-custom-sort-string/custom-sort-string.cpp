class Solution {
public:
    string customSortString(string order, string s) {
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
};