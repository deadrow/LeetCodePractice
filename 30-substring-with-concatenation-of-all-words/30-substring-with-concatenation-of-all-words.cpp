class Solution {
public:
    vector<int> ret;
    unordered_map<string,int> dict;
    int wordSize;
    int totalWordCount;
    
    void slidingWindowSubstring(int start, string s)
    {
        unordered_map<string,int> curDict(dict);
        
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
            
            // if current word is small, increase word size
            if(j-i < windowSize)
            {
                j += wordSize;
            }
            else if(j-i == windowSize)
            {
                // word is equal to window size. If all the entries
                // in curDict becomes 0 that means we have found the match
                // curWordCount is tracking that. If not, remove the word
                // from our sliding window and increment its count in dict
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
        
        // We have to check till wordsize to handle cases like
        // s = "afoobar" words = ["foo", "bar"]
        for(int i=0;i<wordSize;i++)
        {
            slidingWindowSubstring(i, s);
        }

        return ret;
    }
};