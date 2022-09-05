class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(password.empty() || password.size() < 8)
            return false;
        
        bool oneUpper = false;
        bool oneLower = false;
        bool oneDigit = false;
        bool oneSpecial = false;
        
        for(int i=0;i<password.size();i++)
        {
            if(i == 0 || password[i-1] != password[i])
            {
                if(isupper(password[i]))
                    oneUpper = true;
                else if(islower(password[i]))
                    oneLower = true;
                else if(isdigit(password[i]))
                    oneDigit = true;
                else
                    oneSpecial = true;
            }
            else
                return false;
        }
        
        if(oneUpper && oneLower && oneDigit && oneSpecial)
            return true;
        
        return false;
    }
};