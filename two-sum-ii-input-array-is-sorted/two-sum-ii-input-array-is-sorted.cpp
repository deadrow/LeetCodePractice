class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size()-1;
        
        while(low < high)
        {
            int curSum = numbers[low] + numbers[high];
            if(curSum == target)
                return {low+1, high+1};
            else if(curSum < target)
                low++;
            else
                high--;
        }
        
        return {-1, -1};
    }
};
