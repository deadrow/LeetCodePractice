class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int res = max_so_far;
        
        for(int i=1;i<nums.size();i++)
        {
            int cur = nums[i];
            
            // 2 negatives can make bigger positive
            // hence first find overall max
            int tempMax = max(cur, max(min_so_far*cur, max_so_far*cur));
            
                        // now find min so far
            min_so_far = min(cur, min(min_so_far*cur, max_so_far*cur));
            
            // now tempMax is our cur maxmimum
            max_so_far = tempMax;
            
            res = max(res, max_so_far);
        }
        
        return res;
    }
};