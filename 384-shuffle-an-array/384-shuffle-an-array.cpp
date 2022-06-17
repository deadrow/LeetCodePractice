class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
        // srand(time(nullptr));
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> res = nums;

        int n = res.size();
        int remaining = res.size();
        for(int i=n-1;i>=0;i--)
        {
            int newIndex = rand()% remaining;
            swap(res[i], res[newIndex]);
            remaining--;
        }
        
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */