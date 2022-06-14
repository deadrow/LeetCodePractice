class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrs;
        for(auto it : nums)
            numStrs.push_back(to_string(it));
        
        sort(numStrs.begin(), numStrs.end(), [](const string& a, const string& b){
            string s1 = a+b;
            string s2 = b+a;
            return s1 > s2;
        });
        
        if(numStrs[0] == "0")
            return "0";
        
        string res;
        for(auto it : numStrs)
            res += it;
        
        return res;
    }
};