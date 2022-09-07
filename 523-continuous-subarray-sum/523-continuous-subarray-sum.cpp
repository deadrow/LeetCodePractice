class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int> dict;
        dict[0] = 0;
        
        // LOGIC
        // if nums = [23,2,4,6,7], k = 6
        // sum % k will only repeat if we add multiple of k
        // Eg. 7 % 3 == 1 then (7+6) % 3 == 1 
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            if(dict.find(sum%k) == dict.end())
                dict[sum%k] = i+1;
            else if(dict[sum%k] < i) 
                return true;
        }
        return false;
    }
};