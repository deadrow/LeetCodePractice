class BIT{
private:
    vector<int> bit;
public:
    BIT(int size=0){
        bit.resize(size+1, 0);
    }
    int getSum(int idx)
    {
        // get sum of [1....idx]
        int sum = 0;
        for(++idx;idx>0;idx -= (idx&-idx))
            sum += bit[idx];
        return sum;
    }

    void update(int idx, int val)
    {
        for(++idx;idx<bit.size();idx += (idx & -idx))
            bit[idx] += val;
    }
};
class NumArray {
public:
    BIT bit;
    vector<int> nums;
    NumArray(vector<int>& nums) {
        this->bit = BIT(nums.size());
        this->nums = nums;
        for(int i=0;i<nums.size();i++)
            bit.update(i, nums[i]);
    }
    
    void update(int index, int val) {
        bit.update(index, val - nums[index]);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return bit.getSum(right)-bit.getSum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */