class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        auto heapSort = [&](){
            priority_queue<int, vector<int>, greater<>>pq;
            for(auto it : nums)
                pq.push(it);

            nums.clear();

            while(!pq.empty())
            {
                nums.push_back(pq.top());
                pq.pop();
            }
        };
        
        // heapSort();
        
        std::function<void(vector<int>::iterator,vector<int>::iterator)> mergeSort = [&](auto low, auto high){
            if(high-low > 1)
            {
                auto mid = low + (high-low)/2;
                mergeSort(low, mid);
                mergeSort(mid, high);
                inplace_merge(low, mid, high);
            }
        };
        
        mergeSort(nums.begin(), nums.end());
        return nums;
    }
};