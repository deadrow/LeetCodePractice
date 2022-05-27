class Solution {
public:
    vector<vector<int>> memo;
    int solve(int eggs, int floors)
    {
        if(floors == 0 || floors == 1)
            return floors;
        
        if(eggs == 1)
            return floors;
        
        if(memo[eggs][floors] != -1)
            return memo[eggs][floors];
        
        int ans = INT_MAX;
        int low = 1;
        int high = floors;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            int left = solve(eggs-1, mid-1);
            int right = solve(eggs, floors-mid);

            int res = 1 + max(left, right);
            ans = min(ans, res);
            
            if(left < right)
                low = mid+1;
            else
                high = mid-1;
        }
        
        return memo[eggs][floors] = ans;
    }
    
    int superEggDrop(int k, int n) {
        memo.resize(k+1, vector<int>(n+1,-1));
        return solve(k, n);
    }
};