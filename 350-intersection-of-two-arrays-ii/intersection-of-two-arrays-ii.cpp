class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>common(1002), cur(1002);
        for(auto it : nums1)
            common[it]++;
        for(auto it : nums2)
            cur[it]++;
        for(int i=0;i<1002;i++)
            common[i]= min(common[i], cur[i]);
        vector<int>ret;
        for(int i=0;i<1002;i++){
            while(common[i]--)
                ret.push_back(i);
        }
        return ret;
    }
};