class Solution {
public:
    int maxIcecreams = 0;
    
    void backtrack(vector<int>& costs, vector<int>& cur, int cur_i, int n, int target)
    {
        if(target < 0)
            return;
        
        if(target == 0 || (cur_i == n && target > 0))
        {
            maxIcecreams = max(maxIcecreams, (int)cur.size());
            return;
        }
        
        for(int i=cur_i;i<costs.size();i++)
        {
            cur.push_back(costs[i]);
            backtrack(costs, cur, i+1, n, target-costs[i]);
            cur.pop_back();
        }
    }
    
    int maxIceCream1(vector<int>& costs, int coins) {
        
        int sum = 0;
        sum = accumulate(costs.begin(), costs.end(), 0);
        
        if(sum <= coins)
            return costs.size();
        
        sort(costs.begin(), costs.end());
        
        vector<int> cur;
        backtrack(costs, cur, 0, costs.size(), coins);
        return maxIcecreams;
    }
    
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(), costs.end());
        
        int maxCoins = 0;
        for(int i=0;i<costs.size();i++)
        {
            if(costs[i] <= coins)
            {
                coins -= costs[i];
                maxCoins++;
            }
        }
        
        return maxCoins;
    }
};