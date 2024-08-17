class Solution {
public:
    int findPairs1(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count=0;
        for(auto& it : nums) mp[it]++;
        for(auto& it : mp){
            if(k>0 and mp.count(it.first+k)) count++;
            else if(k==0 and it.second > 1) count++;
        }
        return count;
    }
    // 2 pointers
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low=0,high=low+1;
        int count=0;
        while(low<nums.size() and high < nums.size()){
            int diff = nums[high]-nums[low];
            if(diff == k) {
                count++;
                low++;
                while(low<nums.size() and nums[low] == nums[low-1]) low++;
            } else if(diff < k)
                high++;
            else
                low++;
            if(low==high)high++;
        }
        return count;
    }
};