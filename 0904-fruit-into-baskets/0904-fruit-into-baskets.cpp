class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>cache;
        
        int i=0;
        int j=0;
        
        int maxFruits = 0;
        int curFruits = 0;
        while(j<fruits.size())
        {
            cache[fruits[j]]++;
            
            if(cache.size() <= 2)
            {
                curFruits++;
                maxFruits = max(maxFruits, curFruits);
                j++;
            }
            else
            {
                cache[fruits[i]]--;
                if(cache[fruits[i]] == 0)
                    cache.erase(fruits[i]);
                
                i++;
                j++;
            }
        }
        
        return maxFruits;
    }
};