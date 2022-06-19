class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";
        
        string res;
        if(numerator < 0 ^ denominator < 0)
            res += "-";
        
        long dividend = abs((long)numerator);
        long divisor = abs((long)denominator);
        
        res += to_string(dividend/divisor);
        
        long remainder = dividend % divisor;
        if(remainder == 0)
            return res;
        
        res += ".";
        unordered_map<long, int> dict;
        while(remainder)
        {
            if(dict.find(remainder) != dict.end())
            {
                res.insert(dict[remainder], "(");
                res += ")";
                break;
            }
            
            dict[remainder] = res.length();
            remainder *= 10;
            res += to_string(remainder/divisor);
            remainder %= divisor;
        }
        
        return res;
    }
};