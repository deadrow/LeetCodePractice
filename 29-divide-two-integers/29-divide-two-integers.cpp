class Solution {
public:
    int divide(int dividend, int divisor) {
                if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        int negative = 2;
        if(dividend > 0)
        {
            dividend = -dividend;
            negative--;
        }
        
        if(divisor > 0)
        {
            divisor = -divisor;
            negative--;
        }
        
        int quotient = 0;
        
        vector<int> powOfTwos;
        vector<int> values;
        
        int powOfTwo = -1;
        int value = divisor;
        while(dividend <= value)
        {
            values.push_back(value);
            powOfTwos.push_back(powOfTwo);
            if (value < INT_MIN/2) {
                break;
            }
            value *= 2;
            powOfTwo *= 2;
        }
        
        for(int i=values.size()-1; i>=0;i--)
        {
            if(dividend <= values[i])
            {
                dividend -= values[i];
                quotient += powOfTwos[i];
            }
        }
        
        return (negative!= 1 ? -quotient: quotient);
    }
};