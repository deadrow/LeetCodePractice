class Solution {
public:
    unordered_map<int,int> cache;
    int quickselect(vector<int>& unique, int low, int high, int k)
    {
        int pivot = cache[unique[high]];
        int left = low;
        
        for(int i=low;i<high;i++)
        {
            if(cache[unique[i]] <= pivot)
            {
                swap(unique[left], unique[i]);
                left++;
            }
        }
        
        swap(unique[left], unique[high]);
        
        if(k < left) // meaning in 1st half
            return quickselect(unique, low, left-1, k);
        else if(k > left)
            return quickselect(unique, left+1, high, k);
        return unique[left];
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(auto it : nums)
            cache[it]++;
        
        vector<int> unique;
        for(auto it : cache)
        {
            unique.push_back(it.first);
        }
        
        int low = 0;
        int high = unique.size()-1;
        quickselect(unique, low, high, unique.size()-k);
        
        vector<int> res;
        for(int i=unique.size()-k;i<unique.size();i++)
            res.push_back(unique[i]);
        return res;
    }
};