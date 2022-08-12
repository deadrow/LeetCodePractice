class Solution {
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int>nums;
        for(int i=1;i<n;i++)
        {
            nums.push_back(i);
            fact *= i;
        }
        
        nums.push_back(n); // For eg. if n = 4 and nums would be {1,2,3,4} and factorial would be 6
        
        k--; // because of 0 index array
        
        string ans;
        while(nums.size() > 0)
        {
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin() + k/fact);
            k = k % fact;
            
            if(nums.size() > 0)
                fact /= nums.size();
        }
        
        return ans;
    }
};