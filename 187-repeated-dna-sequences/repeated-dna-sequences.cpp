class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int k = 10;
        if(s.size() < k) return {};

        long base = 26;
//        unordered_map<char, int> to_int = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        long powerk = pow(base, k-1);
        long hash = 0;
        int i=0;
        
        unordered_set<long>dict;
        unordered_set<string>ret;
        for(int j=0;j<s.size();j++){
            hash = hash*base + (s[j]-'A'+1);
            if(j-i+1 == k){
                if(dict.count(hash))
                    ret.insert(s.substr(i, j-i+1));
                dict.insert(hash);
                hash = hash - (s[i]-'A'+1)*powerk;
                
                i++;
            }
        }
        return vector<string>(ret.begin(), ret.end());
    }
};