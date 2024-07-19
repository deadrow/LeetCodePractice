class Solution {
public:
    vector<int>prefix;
    Solution(vector<int>& w) {
        prefix = w;
        for(int i=1;i<prefix.size();i++){
            prefix[i] += prefix[i-1];
        }
    }
    
    int pickIndex() {
        int rIdx = rand()%(prefix.back());
        int idx = upper_bound(prefix.begin(), prefix.end(), rIdx)- prefix.begin();
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */