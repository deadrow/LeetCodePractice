class Solution {
public:
    // 1st approach
    int findKthLargest1(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0;i<k;i++)
            pq.push(nums[i]);
        
        for(int i=k;i<nums.size();i++)
        {
            if(nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        return pq.top();
    }

    // 2nd approach
    int findKthLargest2(vector<int>& nums, int k) {
        priority_queue<int>pq;
        
        for(int i=0;i<nums.size();i++)
            pq.push(nums[i]);
        
        for(int i=0;i<k-1;i++)
            pq.pop();

        return pq.top();
    }

    int quickselect(vector<int>& nums, int low, int high, int k){
        int pivotVal = nums[high];
        int p=low;
        for(int i=low;i<high;i++){
            if(nums[i]<=pivotVal){
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[p], nums[high]);
        if(k<p) return quickselect(nums, low, p-1, k);
        else if(k>p) return quickselect(nums, p+1, high, k);
        return nums[p];
    }
    // quickselect
    int findKthLargest3(vector<int>& nums, int k) {
        return quickselect(nums, 0, nums.size()-1, nums.size()-k);
    }

    int quickselect(vector<int>& nums, int k){
        int pivotVal = nums[rand()%nums.size()];
        vector<int>left,mid,right;
        for(int num : nums){
            if(num>pivotVal)
                left.push_back(num);
            else if(num<pivotVal)
                right.push_back(num);
            else 
                mid.push_back(num);
        }

        if(k<=left.size()) return quickselect(left, k);
        else if(k>left.size()+mid.size()) return quickselect(right, k-left.size()-mid.size());
        return pivotVal;
    }
    // quickselect
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, k);
    }
};