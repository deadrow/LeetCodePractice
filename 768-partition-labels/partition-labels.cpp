class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>last;
        for(int i=s.size()-1;i>=0;i--){
            if(!last.count(s[i]))
                last[s[i]] = i;
        }

        vector<int> ret;
        int start=0, end=0;
        for(int i=0;i<s.size();i++){
            end = max(end, last[s[i]]);
            if(i == end) {
                ret.push_back(end-start+1);
                start = i+1;
            }
        }
        return ret;
    }
};