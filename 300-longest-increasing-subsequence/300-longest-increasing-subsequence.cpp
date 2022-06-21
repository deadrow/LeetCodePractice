class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> subSet;
        subSet.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            int num = nums[i];
            if(num > subSet[subSet.size()-1])
                subSet.push_back(num);
            else
            {
                int j=0;
                while(num > subSet[j])
                    j++;
                
                subSet[j] = num;
            }
        }
        
        return subSet.size();
    }
};