class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        multiset<int, greater<int>>low;
        multiset<int>high;
        vector<double>medians;
        for(int j=0;j<nums.size();j++){
            low.insert(nums[j]);
            high.insert(*low.begin());
            low.erase(low.begin());
            if(low.size() < high.size()){
                low.insert(*high.begin());
                high.erase(high.begin());
            }
            if(j-i+1 == k){
                if(k&1)
                    medians.push_back(*low.begin());
                else
                    medians.push_back(((double)*low.begin() + (double)*high.begin())/2.0);

                if(nums[i] <= *low.begin())
                    low.erase(low.find(nums[i]));
                else
                    high.erase(high.find(nums[i]));
                    i++;
            }
        }
        return medians;
    }
};