class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string>tokens;
        string cur;
        while(getline(ss, cur, '/')){
            if(cur == ".." and !tokens.empty())
                tokens.pop_back();
            else if(cur == "." or cur == "/")
                continue;
            else {
                if(cur != ".." and !cur.empty())
                    tokens.push_back(cur);
            }
                
        }

        if(tokens.empty()) return "/";
        string res;
        for(auto it : tokens)
            res += "/" + it;

        return res.substr(0, res.size());
    }
};