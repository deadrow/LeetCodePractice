class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k > s.size()) return false;
        unordered_set<string>nums;
        for(int i=0;i<=s.size()-k;i++)
        {
            nums.insert(s.substr(i,k));
        }
        
        return nums.size() == (int)pow(2,k);
    }
};