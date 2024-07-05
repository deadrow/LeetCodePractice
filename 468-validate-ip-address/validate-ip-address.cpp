class Solution {
public:
    string validIPAddress(string queryIP) {
        if(queryIP.empty()) return "Neither";

        stringstream ipv4(queryIP);

        if(queryIP[0] == '.' or queryIP[queryIP.size()-1] == '.') return "Neither";

        string cur;
        vector<string>tokens;
        // first check ipv4
        while(getline(ipv4, cur, '.')){
            tokens.push_back(cur);
        }

        if(tokens.size() == 4){
            for(auto& it : tokens){
                string part = it;
                if(part.empty()) return "Neither";
                if(part.size() > 1 and part[0] == '0')
                    return "Neither";
                if(part.size()<0 or part.size()>3) return "Neither";
                for(auto curChar : part){
                    if(!isdigit(curChar)) return "Neither";
                }
                if(stoi(part)<0 or stoi(part)>255) return "Neither";
            }
            return "IPv4";
        }

        tokens.clear();

        if(queryIP[0] == ':' or queryIP[queryIP.size()-1] == ':') return "Neither";
        // Now check ipv6
        cur = "";
        stringstream ipv6(queryIP);
        while(getline(ipv6, cur, ':')){
            tokens.push_back(cur);
        }
        if(tokens.size() != 8) return "Neither";

        for(auto& it : tokens){
            string part = it;
            if(part.empty() or part.size() > 4) return "Neither";

            for(auto curChar : part)
                if(!isdigit(curChar) and !isalpha(curChar) or !isxdigit(curChar)) return "Neither";
        }

        return "IPv6";
    }
};