class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> left_max(n);
        vector<int> right_max(n);
        
        int ans = 0;
        int curMax = 0;
        
        for(int i=0;i<n;i++)
        {
            left_max[i] = curMax;
            curMax = max(curMax, height[i]);
        }
        
        curMax = 0;
        for(int i=n-1;i>=0;i--)
        {
            right_max[i] = curMax;
            curMax = max(curMax, height[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            int cur = min(right_max[i], left_max[i]) - height[i];
            if(cur > 0)
                ans = ans + cur;
        }
        
        return ans;
    }
};