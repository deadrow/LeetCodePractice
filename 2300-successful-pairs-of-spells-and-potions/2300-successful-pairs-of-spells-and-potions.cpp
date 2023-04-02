class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        
        vector<int>ret;
        for(auto it : spells)
        {
            long num = ceil((double)success/it);
            auto upper = lower_bound(potions.begin(), potions.end(), num);
            if(upper != potions.end())
                ret.push_back(potions.size() - (upper-potions.begin()));
            else
                ret.push_back(0);
        }
        
        return ret;
    }
};