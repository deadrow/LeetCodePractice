class Solution {
public:
    vector<int> count;
    using iterator = vector<pair<int,int>>::iterator;
    void sort_count(iterator low, iterator high)
    {
        if(high-low <= 1)
            return;
        
        iterator mid = low + (high-low)/2;
        sort_count(low, mid);
        sort_count(mid, high);
        
        for(iterator i=low,j=mid;i < mid;i++)
        {
            while(j<high && i->first > j->first) j++;
            count[i->second] += j-mid;
        }
        
        inplace_merge(low, mid, high);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int,int>> pairs;
        
        count.resize(n);
        
        for(int i=0;i<n;i++)
        {
            pairs.push_back({nums[i], i});
        }
        
        sort_count(pairs.begin(), pairs.end());
        return count;
    }
};