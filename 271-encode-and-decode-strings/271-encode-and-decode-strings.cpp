class Codec {
public:
    string delim ="$$#$$";
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for(auto it : strs)
            res += it + delim;
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delim)) != std::string::npos) {
            token = s.substr(0, pos);
            res.push_back(token);
            s.erase(0, pos + delim.length());
        }
        
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));