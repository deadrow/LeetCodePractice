class Solution {
public:
    vector<int>prefix;
    Solution(vector<int>& w) {
        prefix = w;
        
        for(int i=1;i<prefix.size();i++)
        {
            prefix[i] += prefix[i-1];
        }
    }
    
    int pickIndex() {
        int idx = rand()% prefix.back();
        
        auto it = upper_bound(prefix.begin(), prefix.end(), idx);
        return it-prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */