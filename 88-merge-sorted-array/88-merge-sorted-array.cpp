class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size = (int)nums1.size();
        int high_n1 = m-1;
        int high_n2 = n-1;
        
        int pos = size-1;
        while(high_n1 >=0 && high_n2 >=0)
        {
            if(nums1[high_n1] < nums2[high_n2])
            {
                nums1[pos] = nums2[high_n2];
                high_n2--;
            }
            else
            {
                nums1[pos] = nums1[high_n1];
                high_n1--;
            }
            pos--;
        }
        
        while(high_n2>=0)
        {
            nums1[pos] = nums2[high_n2];
            high_n2--;
            pos--;
        }
    }
};