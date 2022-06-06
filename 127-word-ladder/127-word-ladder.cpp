class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        if(dict.find(endWord) == dict.end())
            return 0;
        
        queue<string> bfs;
        bfs.push(beginWord);
        
        int steps = 1;
        while(!bfs.empty())
        {
            int size = bfs.size();
            for(int i=0;i<size;i++)
            {
                string cur = bfs.front();
                bfs.pop();

                if(cur == endWord)
                    return steps;

                for(int i=0;i<cur.size();i++)
                {
                    for(int j=0;j<26;j++)
                    {
                        string newString = cur;
                        newString[i] = 'a' + j;
                        if(dict.find(newString) != dict.end())
                        {
                            bfs.push(newString);
                            dict.erase(newString);
                        }
                            
                    }
                }
            }

            steps++;
        }
        
        return 0;
    }
};