class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<string>nums{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        
        queue<string> bfs;
        for(auto it : nums)
            bfs.push(it);
        
        vector<int>ret;
        while(!bfs.empty())
        {
            
            string cur = bfs.front();
            bfs.pop();
            
            if(cur.size() == n)
            {
                if(cur[0]!= '0')
                    ret.push_back(stoi(cur));
                continue;
            }
                
            int prev = cur.back() - '0';
            if(prev + k < 10)
                bfs.push(cur + char(prev + k + '0'));
 
            if(k > 0 && prev - k >= 0)
                bfs.push(cur + char(prev - k + '0'));
        }
        
        return ret;
    }
};