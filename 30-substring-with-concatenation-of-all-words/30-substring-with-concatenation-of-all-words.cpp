class Solution {
public:
    vector<int> ret;
    unordered_map<string,int> dict;
    int wordSize;
    int totalWordCount;
    
    void slidingWindowSubstring(int start, string s)
    {
        unordered_map<string,int> curDict = dict;
        
        int i = start;
        int j = i+wordSize;
        
        int curWordCount = curDict.size();
        int windowSize = wordSize*totalWordCount;
        
        while(j <= s.size())
        {
            string cur = s.substr(j-wordSize, wordSize);
            if(curDict.find(cur) != curDict.end())
            {
                curDict[cur]--;
                if(curDict[cur] == 0)
                    curWordCount--;
            }
            
            if(j-i < windowSize)
            {
                j += wordSize;
            }
            else if(j-i == windowSize)
            {
                if(curWordCount == 0)
                {
                    ret.push_back(i);
                }
                    
                string last = s.substr(i, wordSize);
                if(curDict.find(last) != curDict.end())
                {
                    if(curDict[last] == 0)
                        curWordCount++;
                    curDict[last]++;
                }
                
                i += wordSize;
                j += wordSize;
            }
        }
    }
    
    vector<int> findSubstring(string s, vector<string> words) {

        for(auto it : words)
            dict[it]++;
        
        wordSize = words[0].size();
        totalWordCount = words.size();
        
        for(int i=0;i<wordSize;i++)
        {
            slidingWindowSubstring(i, s);
        }

        return ret;
    }
};