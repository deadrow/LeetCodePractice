class Solution {
public:
    vector<int>remaining;
    Solution(int n, vector<int>& blacklist) {
        unordered_set<int>mp(blacklist.begin(), blacklist.end());
        for(int i=0;i<n;i++){
            if(!mp.count(i)) remaining.push_back(i);
            if(remaining.size() == 1e5) break; 
        }
    }
    
    int pick() {
        return remaining[rand()%remaining.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */