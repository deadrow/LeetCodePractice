class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // O(n2) solution. This gets TLE in leetcode for
        // one there where it is all zero but will work for
        // interviews.
        unordered_map<int,int>dict;
        set<vector<int>>ret;
        unordered_set<int>dups;
        for(int i=0;i<nums.size();i++){
            if(dups.insert(nums[i]).second) {
                for(int j=i+1;j<nums.size();j++) {
                int complement = -(nums[i]+nums[j]);
                if(dict.count(complement)) {
                    if(i!= dict[complement] and j!= dict[complement]) {
                        vector<int>triplet{nums[i], nums[j], complement};
                        sort(triplet.begin(), triplet.end());
                        ret.insert(triplet);
                    }  
                }
                dict[nums[j]]=j;
                }
            }
        }

        return vector<vector<int>>(ret.begin(), ret.end());
    }
};