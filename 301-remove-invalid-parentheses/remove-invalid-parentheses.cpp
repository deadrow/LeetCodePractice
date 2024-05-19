class Solution {
public:
    vector<string> ret;
    bool valid(string arr)
    {
        int balanced = 0;
        for(auto c : arr)
        {
            if(c == '(')
                balanced++;
            else if(c == ')')
                balanced--;
            if(balanced < 0) return false;
        }
        
        return (balanced == 0);
    }
    
    vector<string> removeInvalidParentheses(string s) {
        queue<string>bfs;
        unordered_set<string>visited;
        bfs.push(s);
        visited.insert(s);

        bool found = false;
        while(!bfs.empty()) {
            string cur = bfs.front();
            bfs.pop();

            cout << cur << endl;
            if(valid(cur)) {
                ret.push_back(cur);
                found = true;
            }

            if(found) continue;

            for(int i=0;i<cur.size();i++) {
                if(cur[i] != '(' and cur[i] != ')') continue;

                string child = cur.substr(0,i) + cur.substr(i+1);
                if(!visited.count(child)) {
                    bfs.push(child);
                    visited.insert(child);
                }
            }
        }

        return ret;
    }
};