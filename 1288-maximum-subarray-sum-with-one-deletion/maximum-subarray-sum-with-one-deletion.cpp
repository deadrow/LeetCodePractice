class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int curSum=arr[0];
        int withoutSum=arr[0];
        int maxSum=max(curSum, withoutSum);
        for(int i=1;i<arr.size();i++){
            // LOGIC
            // sqauredSum would be max of
            // 1. Cursum + square of current num
            // 2. Only squared sum of current num
            // 3. Squared sum + current num
            withoutSum = max({arr[i], withoutSum+arr[i], curSum});
            curSum = max(curSum+arr[i], arr[i]);
            maxSum = max({maxSum, withoutSum, curSum});
        }
        return maxSum;
    }
};