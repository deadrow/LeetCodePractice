class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivotIdx = n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=nums[i+1])
                pivotIdx=i;
            else break;
        }

        if(pivotIdx == 0) {
            // descending order
            reverse(nums.begin(), nums.end());
        } else if(pivotIdx == n-1) {
            // increasing order
            swap(nums[n-2], nums[n-1]);
        } else {
            int i=pivotIdx;
            for(;i<n;i++){
                if(nums[i] > nums[pivotIdx-1])
                    continue;
                else break;
            }
            cout << pivotIdx << "," << i;
            swap(nums[pivotIdx-1], nums[i-1]);
            reverse(nums.begin()+pivotIdx, nums.end());
        }
    }
};