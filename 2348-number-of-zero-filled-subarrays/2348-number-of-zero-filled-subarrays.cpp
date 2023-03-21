class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        unordered_map<int,int>dict;
        
        int counter = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] != 0)
            {
                dict[counter]++;
                counter = 0;
            }
            else
                counter++;
        }
        
        dict[counter]++;
        
        long total = 0;
        for(auto it : dict)
        {
            long count = ((long)it.first*(long)(it.first+1))/2;
            total += (long)it.second* count;
        }
        
        return total;
    }
};