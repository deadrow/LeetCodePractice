class Solution {
public:
    vector<int> majorityElement1(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ret;
        for(auto it : nums){
            mp[it]++;
            if(mp[it] == nums.size()/3+1) ret.push_back(it);
        }
        return ret;
    }

    // Boyer Moore algorithm similar to https://leetcode.com/problems/majority-element/
    vector<int> majorityElement(vector<int>& nums) {
        // For n/3 there can be 2 elements which are majority
        int cnt1=0, cnt2=0;
        int el1=INT_MIN, el2=INT_MIN;
        for(auto it : nums){
            if(cnt1==0 and el2!=it)
                cnt1=1,el1 = it;
            else if(cnt2==0 and el1!=it)
                cnt2=1,el2=it;
            else if(el1==it)
                cnt1++;
            else if(el2==it)
                cnt2++;
            else
                cnt1--,cnt2--;
        }

        cnt1=0,cnt2=0;
        for(auto it : nums){
            if(el1==it)cnt1++;
            else if(el2==it)cnt2++;
        }
        vector<int>ret;
        if(cnt1 >= nums.size()/3+1) ret.push_back(el1);
        if(cnt2 >= nums.size()/3+1) ret.push_back(el2);
        sort(ret.begin(), ret.end());
        return ret;
    }

};