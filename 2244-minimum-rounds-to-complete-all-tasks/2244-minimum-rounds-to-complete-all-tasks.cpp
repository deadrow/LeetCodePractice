class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>dict;
        
        for(auto it : tasks)
            dict[it]++;
        
        int count = 0;
        for(auto it : dict)
        {
            if(it.second >= 3)
            {
                count += (it.second % 3 != 0) ? 1 : 0;
                count += it.second / 3;
            }
            else if(it.second >= 2)
            {
                count += it.second / 2;
            }
            else
                return -1;
        }
        
        return count;
    }
};