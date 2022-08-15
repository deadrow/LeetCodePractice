class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long product = 1;
        
        for(auto it : nums)
        {
            if(it < 0)
                product *= -1;
            else if(it == 0)
            {
                product = 0;
                break;
            }
        }
        
        if(product == 0)
            return 0;
        else if(product < 0)
            return -1;
        
        return 1;
    }
};