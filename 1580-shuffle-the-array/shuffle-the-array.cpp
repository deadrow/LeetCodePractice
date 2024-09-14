class Solution {
public:
    vector<int> shuffle1(vector<int>& nums, int n) {
        vector<int>ret(2*n);
        for(int i=0,j=0;i<n;i++,j+=2){
            ret[j] = nums[i];
            ret[j+1] = nums[i+n];
        }
        return ret;
    }
    // store 2 numbers in bit
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i=n;i<2*n;i++){
            int secondNum = nums[i] << 10;
            nums[i-n] |= secondNum;
        }
        int allOne = pow(2, 10) - 1; // 10 ones
        int j=nums.size()-2;
        for(int i=nums.size()-1;i>=n;i--){
            int secondNum = nums[i-n] >> 10;
            int firstNum = nums[i-n] & allOne;
            nums[j] = firstNum;
            nums[j+1] = secondNum;
            j -= 2;
        }
        return nums;
    }
};