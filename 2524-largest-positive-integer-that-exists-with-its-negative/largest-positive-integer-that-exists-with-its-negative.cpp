class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int>mp;
        int maxNum = INT_MIN;
        for(auto it : nums){
            if(mp.count(-it))
                maxNum = max(maxNum, abs(it));
            mp.insert(it);
        }

        return maxNum==INT_MIN ? -1 : maxNum;
    }
};