class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n);
        prefix[0] = nums[0];

        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1]+nums[i];
        }

        vector<int>ret(n);
        for(int i=0;i<n;i++)
        {
            int leftSum = 0;
            if(i>0)
                leftSum = prefix[i-1];

            int rightSum = prefix[n-1]- prefix[i];

            ret[i] = abs(i*nums[i] - leftSum) + abs((n-i-1)*nums[i] - rightSum);

        }

        return ret;
    }
};