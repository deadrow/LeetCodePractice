class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> dict;
        for(auto it : arr)
            dict[it]++;
        
        unordered_map<int,int> reverse;
        for(auto it : dict)
        {
            if(reverse.find(it.second) != reverse.end())
                return false;
            
            reverse[it.second] = it.first;
        }
        
        return true;
    }
};