class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
        srand(time(nullptr));
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> res = nums;

        for(int i=0;i< nums.size();i++)
        {
            int newIndex = rand()% (nums.size());
            swap(res[i], res[newIndex]);
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