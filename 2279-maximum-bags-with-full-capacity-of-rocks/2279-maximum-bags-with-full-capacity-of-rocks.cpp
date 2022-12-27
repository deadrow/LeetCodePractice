class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int>remaining(n);
        
        for(int i=0;i<n;i++)
            remaining[i] = capacity[i]-rocks[i];
        
        sort(remaining.begin(), remaining.end());
        
        int idx = 0;
        while(idx < n && additionalRocks >= remaining[idx])
        {
            if(remaining[idx] != 0)
                additionalRocks -= remaining[idx];
            idx++;
        }
        
        return idx;
    }
};