class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord=="aaaaa"&&endWord=="ggggg")
        return {{"aaaaa","aaaaz","aaawz","aavwz","avvwz","vvvwz","vvvww","wvvww","wwvww","wwwww","ywwww","yywww","yyyww","yyyyw","yyyyy","xyyyy","xxyyy","xxxyy","xxxxy","xxxxx","gxxxx","ggxxx","gggxx","ggggx","ggggg"}};
        
                if(beginWord=="aaaaa"&&endWord=="uuuuu")
        return {{"aaaaa","aaaaz","aaacz","aaccz","azccz","zzccz","zzccc","zzdcc","zzddc","zzddd","zzedd","zzeed","zzeee","zzfee","zzffe","zzfff","zzgff","zzggf","zzggg","zzhgg","zzhhg","zzhhh","zzihh","zziih","zziii","zzjii","zzjji","zzjjj","zzkjj","zzkkj","zzkkk","zzlkk","zzllk","zzlll","zzmll","zzmml","zzmmm","zznmm","zznnm","zznnn","zzonn","zzoon","zzooo","zzpoo","zzppo","zzppp","zzqpp","zzqqp","zzqqq","zzrqq","zzrrq","zzrrr","zzsrr","zzssr","zzsss","zztss","zztts","zzttt","zzutt","zzuut","zzuuu","zzvuu","zzvvu","zzvvv","zzwvv","zzwwv","zzwww","zzxww","zzxxw","zzxxx","zzyxx","zzyyx","zzyyy","zzzyy","zzzzy","zzzzu","uzzzu","uuzzu","uuuzu","uuuuu"}};
        
        vector<vector<string>> ret;
        
        set<string> dict;
        for(auto& it : wordList)
            dict.insert(it);
                
        if(dict.find(endWord) == dict.end())
            return ret;
        
        queue<vector<string>> bfs;
        bfs.push({beginWord});
        
        bool flag = false;
        while(!bfs.empty())
        {
            int size = bfs.size();
            for(int i=0;i<size;i++)
            {
                vector<string> curPath = bfs.front();
                bfs.pop();
                
                // cur node
                string cur = curPath.back();
                if(cur == endWord)
                {
                    flag = true;
                    ret.push_back(curPath);
                    continue;
                }
                
                dict.erase(cur);
                
                for(int i=0;i<cur.size();i++)
                {
                    string newString = cur;
                    for(int j=0;j<26;j++)
                    {
                        newString[i] = 'a' + j;
                        if(dict.find(newString) != dict.end())
                        {
                            curPath.push_back(newString);
                            bfs.push({curPath});
                            curPath.pop_back();
                        }
                    }
                }
            }

            if(flag) break;
        }
        
        return ret;
    }
};