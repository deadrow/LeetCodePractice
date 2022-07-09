class NumArray {
public:
    vector<int>tree;
    int n;
    
    // segment tree
    void build(vector<int>& arr, int index, int low, int high)
    {
        if(low == high)
        {
            tree[index] = arr[low];
            return;
        }
        
        int mid = low + (high-low)/2;
        build(arr, 2*index+1, low, mid);
        build(arr, 2*index+2, mid+1, high);
        
        tree[index] = tree[2*index+1] + tree[2*index+2];
    }
    
    int query(int index, int low, int high, int l, int r)
    {
        if(l > high || r < low)
            return 0;
        
        if(low >= l && high <= r)
            return tree[index];
        
        int mid = low + (high-low)/2;
        int left = query(2*index+1, low, mid, l, r);
        int right = query(2*index+2, mid+1, high, l, r);
        return left+right;
    }
    
    void update(int index, int i, int value, int low, int high)
    {
        if(low == high)
        {
            tree[index] = value;
            return;
        }
        
        int mid = low + (high-low)/2;
        
        if(i <= mid)
            update(2*index+1, i, value, low, mid);
        else
            update(2*index+2, i, value, mid+1, high);
        
        tree[index] = tree[2*index+1] + tree[2*index+2];
    }
    
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        tree.resize(4*n);
        build(nums, 0, 0, n-1);
    }
    
    void update(int index, int val) {
        update(0, index, val, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */