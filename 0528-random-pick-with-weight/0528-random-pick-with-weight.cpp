class Solution {
public:
    vector<double>weights;
    int size = 0;
    std::discrete_distribution<> dist;
    std::random_device rd;
    std::mt19937 gen;
    Solution(vector<int>& w) : gen(rd()) , dist(w.begin(), w.end())
    {
    }
    
    int pickIndex() {
        return dist(gen);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */