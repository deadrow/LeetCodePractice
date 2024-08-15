class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n, 1);
        vector<int> count(n, 1);
        int maxLen=0;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[j] < nums[i]){
                    if(len[j]+1 > len[i]){
                        len[i] = len[j]+1;
                        count[i]=count[j];
                    }
                    else if(len[j]+1 == len[i]) // we found another LIS with same len so increment the count
                        count[i] += count[j];
                }
            }
        }

        int maxLis = *max_element(len.begin(), len.end());
        int ret=0;
        for(int i=0;i<n;i++)
            if(len[i] == maxLis)
                ret += count[i];
        return ret;
    }
};