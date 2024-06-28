class Solution {
public:
    int _m=0;
    int _n=0;
    set<pair<int,int>>dict;
    Solution(int m, int n):_m(m),_n(n) {
        
    }
    
    vector<int> flip() {
        int randx = rand() % _m;
        int randy = rand() % _n;
        if(!dict.count({randx, randy})) {
            dict.insert({randx, randy});
            return {randx, randy};
        } else return flip();
    }
    
    void reset() {
        dict.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */