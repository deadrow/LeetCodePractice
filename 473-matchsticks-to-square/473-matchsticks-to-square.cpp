class Solution {
public:
    vector<int>knapsackLength;
    vector<int> sticks;
    bool dfs(int cur_i, int targetSum)
    {
        if(cur_i == sticks.size())
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
            if(knapsackLength[i] + sticks[cur_i] > targetSum)
                continue;
            
            knapsackLength[i] += sticks[cur_i];
            if(dfs(cur_i+1, targetSum))
                return true;
            knapsackLength[i] -= sticks[cur_i];
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        
        this->sticks = matchsticks;
        
        int totalSum = accumulate(sticks.begin(), sticks.end(), 0);
        int targetSum = totalSum/4;
        
        if(totalSum % 4  != 0)
            return false;
        
        sort(sticks.begin(), sticks.end(), greater<int>());
        knapsackLength.resize(4, 0);
        return dfs(0, targetSum);
    }
};