class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int maxParam = 0;
        while(i < nums.size()-2)
        {
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];

            if(a+b > c && a+c > b && b+c > a)
                maxParam = max(maxParam, a+b+c);
            
            i++;
        }
        
        
        return maxParam;
    }
};