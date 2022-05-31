class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for(auto it : strs)
        {
            res += it.size();
            res += it;
        }
            
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        
        unsigned idx = 0;
        while(idx < s.length())
        {
            uint8_t curSize = s[idx++];
            string ans;
            while(curSize--)
            {
                ans += s[idx++];
            }
            
            res.push_back(ans);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));