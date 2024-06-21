class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> dict(nums.size()+1);

        for(auto it : nums){
            if(it >=0 and it <= nums.size())
                dict[it] = true;
        }
            
        for(int i=1;i<dict.size();i++){
            if(!dict[i])
                return i;
        }

        return nums.size()+1;
    }
};