class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0)
            return false;
        
        vector<int> divisors{2,3,5};
        for(auto it : divisors)
        {
            while(n % it == 0)
                n /= it;
        }

        if(n == 1)
            return true;
        
        return false;
    }
};