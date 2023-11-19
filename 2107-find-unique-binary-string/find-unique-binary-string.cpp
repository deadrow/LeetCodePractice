class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int n = nums.size();
        unordered_set<string> dict(nums.begin(), nums.end());

        string ret;
        for(unsigned int i=0;i<pow(2,n);i++)
        {
            bitset<16> b{i};
            string num = b.to_string();
            ret = num.substr(16-n);
            if(dict.find(ret) == dict.end())
            {
                break;
            }
        }
        
        return ret;
    }
};