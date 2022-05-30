class Solution {
public:
    bool isPalindrome(string s) {
        string converted;
        for(auto it : s)
        {
            if(!isspace(it) && !ispunct(it))
                converted += tolower(it);
        }
        
        int low = 0;
        int high = converted.size()-1;
        while(low<=high)
        {
            if(converted[low++] != converted[high--])
                return false;
        }
        
        return true;
    }
};