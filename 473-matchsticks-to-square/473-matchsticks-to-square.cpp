class Solution {
public:
    vector<int>knapsackLength;
    bool dfs(vector<int>& matchsticks, int cur_i, int targetSum)
    {
        if(cur_i == matchsticks.size())
        {
            if(knapsackLength[0] == knapsackLength[1] &&
               knapsackLength[1] == knapsackLength[2] &&
               knapsackLength[2] == knapsackLength[3]
               )
                return true;
            return false;
        }
        
        for(int i=0;i<4;i++)
        {
            if(knapsackLength[i] + matchsticks[cur_i] > targetSum)
                continue;
            
            knapsackLength[i] += matchsticks[cur_i];
            if(dfs(matchsticks, cur_i+1, targetSum))
                return true;
            knapsackLength[i] -= matchsticks[cur_i];
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        
        int totalSum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        int targetSum = totalSum/4;
        
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        knapsackLength.resize(4, 0);
        return dfs(matchsticks, 0, targetSum);
    }
};