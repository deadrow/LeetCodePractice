class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> modulos(k);
        modulos[0] = 1;
        
        int sum = 0;
        int count = 0;
        
        for(auto it : nums)
        {
            sum += it;
            int mod = sum % k;
            
            if(mod < 0) mod += k;
            
            count += modulos[mod];
            modulos[mod]++;
        }
        
        return count;
    }
};