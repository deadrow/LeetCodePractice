class Solution {
public:
    unordered_set<string>wordMap;
    
    bool dfs(string word, int start, vector<string>& splits)
    {
        if(start >= word.size())
            return true;
        
        for(int i=start+1;i<=word.size();i++)
        {
            string cur = word.substr(start,i-start);
            if(wordMap.find(cur) != wordMap.end() && dfs(word, i, splits))
            {
                splits.push_back(cur);
                return true;
            }
        }
        
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto it : words)
            wordMap.insert(it);
        
        vector<string> res;
        
        for(auto it : words)
        {
            vector<string>splits;
            bool ret = dfs(it, 0, splits);
            if(ret && splits.size() > 1)
                res.push_back(it);
        }
        
        return res;
    }
};