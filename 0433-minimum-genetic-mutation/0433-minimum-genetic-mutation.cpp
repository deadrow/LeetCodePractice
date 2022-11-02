class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string>dict(bank.begin(), bank.end());
        
        if(dict.find(end) == dict.end())
            return -1;
        
        queue<string>bfs;
        bfs.push(start);
        
        int steps = 0;
        
        while(!bfs.empty())
        {
            int size = bfs.size();
            for(int i=0;i<size;i++)
            {
                string cur = bfs.front();
                bfs.pop();
                
                if(cur == end)
                    return steps;
                
                for(int i=0;i<cur.size();i++)
                {
                    for(auto it : "ACGT")
                    {
                        string newString(cur);
                        if(newString[i] != it)
                        {
                            newString[i] = it;
                            if(dict.find(newString) != dict.end())
                            {
                                bfs.push(newString);
                                dict.erase(newString);
                            }
                        }
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};