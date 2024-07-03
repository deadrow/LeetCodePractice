class SparseVector {
public:
    unordered_map<int,int>idxToVal;
    vector<int> nums;
    SparseVector(vector<int> &nums) : nums(nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0)
                idxToVal[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum=0;
        for(int i=0;i<vec.nums.size();i++){
            if(vec.nums[i] != 0 and idxToVal.count(i)){
                sum += vec.nums[i] * idxToVal[i];
            }
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);