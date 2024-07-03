class SparseVector1 {
public:
    unordered_map<int,int>idxToVal;
    SparseVector1(vector<int> &nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0)
                idxToVal[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector1& vec) {
        int sum=0;
        for(auto& it : idxToVal){
            if(vec.idxToVal.count(it.first))
                sum += it.second * vec.idxToVal[it.first];
        }
        return sum;
    }
};

// 2pointers solution
class SparseVector {
public:
    vector<pair<int,int>>pairs;
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0)
                pairs.push_back({i, nums[i]});
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum=0;
        int i=0,j=0;
        while(i<pairs.size() and j<vec.pairs.size()){
            if(pairs[i].first == vec.pairs[j].first){
                sum += pairs[i].second*vec.pairs[j].second;
                i++,j++;
            } else if(pairs[i].first < vec.pairs[j].first) i++;
            else j++;
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);