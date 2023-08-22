class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret;

        while(columnNumber)
        {
            columnNumber--;
            int rem = columnNumber%26;
            ret += (rem + 'A');
            columnNumber /= 26;
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};