class SparseVector {
public:
    map<int,int>idxToVal;
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0)
                idxToVal[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum=0;
        for(auto& it : idxToVal){
            if(vec.idxToVal.count(it.first))
                sum += it.second * vec.idxToVal[it.first];
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);