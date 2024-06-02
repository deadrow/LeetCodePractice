class Solution {
public:
    vector<vector<int>> threeSum1(vector<int>& nums) {
        // O(n2) solution. This gets TLE in leetcode for
        // one there where it is all zero but will work for
        // interviews.
        unordered_map<int,int>dict;
        set<vector<int>>ret;
        unordered_set<int>dups; // just to avoid all zeros
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

    vector<vector<int>> threeSum(vector<int>& nums) {
        // sorting method
        // O(n2) + O(nlogn) ~= O(n) complexity
        int n = nums.size();
        sort(nums.begin(), nums.end());

        set<vector<int>>ret;
        for(int i=0;i<n;i++){
            int low = i+1;
            int high = n-1;
            while(low<high) {
                int sum = nums[i]+nums[low]+nums[high];
                if(sum == 0){
                    ret.insert({nums[i],nums[low],nums[high]});
                    low++;
                    high--;
                } 
                else if(sum < 0) low++;
                else high--;
            }
        }
        return vector<vector<int>>(ret.begin(), ret.end());
    }
};