class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int min_elem = nums[0];

        int curCount = 0;
        int ops = 0;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i] != nums[i-1])
            {
                curCount = n-i;
                ops += curCount;
                if(nums[i-1] == min_elem)
                    break;
            }
        }

        return ops;
    }
};