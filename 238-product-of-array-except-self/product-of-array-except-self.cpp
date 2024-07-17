class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n);
        left[0]=1;
        for(int i=1;i<n;i++){
            left[i] = left[i-1]*nums[i-1];
        }
        vector<int>right(n);
        right[n-1]=1;
        for(int i=n-2;i>=0;i--){
            right[i]= right[i+1]*nums[i+1];
        }
        vector<int>ret(n);
        for(int i=0;i<n;i++){
            ret[i]= left[i]*right[i];
        }
        return ret;
    }

    vector<int> productExceptSelf1(vector<int>& nums) {
        vector<int>ret(nums.size());
        ret[0]=1;
        for(int i=1;i<nums.size();i++){
            ret[i] = ret[i-1]*nums[i-1];
        }
        int right=1;
        for(int i=nums.size()-1;i>=0;i--){
            ret[i] = ret[i]*right;
            right *= nums[i];
        }
        return ret;
    }
};