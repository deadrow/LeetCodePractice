class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i=nums.size()-2;i>=0;i--) {
            if(i+nums[i] < i+1) {
                // check if it is reachble from anywhere else
                int j = i;
                while(j>=0 and j+nums[j] <= i) j--;
                cout << j;
                if(j < 0) return false;
            }
        }
        return true;
    }
};