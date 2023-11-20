class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int ret = 0;
        for(auto it : garbage)
            ret += it.length();

        int n = travel.size();

        bool m = false;
        bool p = false;
        bool g = false;
        for(int i=n;i>0;i--)
        {
            m = m or garbage[i].find('M') != string::npos;
            p = p or garbage[i].find('P') != string::npos;
            g = g or garbage[i].find('G') != string::npos;

            ret += travel[i-1]* ((m?1:0) + (p?1:0) + (g?1:0));
        }

        return ret;
    }
};