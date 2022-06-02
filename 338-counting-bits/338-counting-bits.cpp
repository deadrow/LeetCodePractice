class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret;
        
        for(int i=0;i<=n;i++)
        {
            bitset<32> bs(i);
            ret.push_back(bs.count());
        }
        
        return ret;
    }
};