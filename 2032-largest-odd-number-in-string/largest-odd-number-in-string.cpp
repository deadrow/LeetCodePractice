class Solution {
public:
    string largestOddNumber(string num) {

        for(int i=num.size()-1;i>=0;i--)
        {
            int cur = num[i]-'0';
            cout << cur;
            if(cur & 1)
                return num.substr(0, i+1);
        }

        return "";
    }
};