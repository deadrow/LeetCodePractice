class Solution {
public:
    unordered_set<int> dict;
    bool isHappy(int n) {
        if(n == 1)
            return true;
        if(dict.find(n) != dict.end())
            return false;
        
        dict.insert(n);
        
        int res = 0;
        while(n)
        {
            int digit = n%10;
            res += digit*digit;
            n /= 10;
        }
        
        return isHappy(res);
    }
};