class Solution {
public:
    enum class state {
        unknown=0,
        increasing,
        decreasing
    };

    bool isMonotonic(vector<int>& nums) {
        state prev = state::unknown;
        for(int i=1;i<nums.size();i++) {
            int diff = nums[i]-nums[i-1];
            state st = diff >= 0 ? (diff == 0 ? prev:state::increasing) : state::decreasing;
            if(prev != state::unknown && prev != st) return false;
            prev = st; 
        }

        return true;
    }
};