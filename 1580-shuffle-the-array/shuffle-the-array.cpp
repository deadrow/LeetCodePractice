class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ret(2*n);
        for(int i=0,j=0;i<n;i++,j+=2){
            ret[j] = nums[i];
            ret[j+1] = nums[i+n];
        }
        return ret;
    }
};