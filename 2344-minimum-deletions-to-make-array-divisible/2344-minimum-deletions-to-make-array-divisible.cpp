class Solution {
public:
    int gcd(int a, int b)
    {
      if (a == 0)
        return b;
      return gcd(b % a, a);
    }

    // Function to find gcd of array of
    // numbers
    int findGCD(vector<int>& nums)
    {
      int result = nums[0];
      for (int i = 1; i < nums.size(); i++)
      {
        result = gcd(nums[i], result);

        if(result == 1)
            return 1;
      }
    
      return result;
    }
    
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        
        int ops = 0;
        int gcd = findGCD(numsDivide);
        
        for(int i=0;i<nums.size();i++)
        {
            if(gcd % nums[i] != 0)
                ops++;
            else
                break;
        }
        
        return ops == nums.size() ? -1 : ops;
    }
};