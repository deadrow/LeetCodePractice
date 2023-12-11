class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();

        int curCount = 1;
        int cur = arr[0];
        for(int i=1;i<n;i++)
        {
            if(cur == arr[i])
            {
                curCount++;
                if(curCount > n/4)
                    return arr[i];
            }
            else
            {
                cur = arr[i];
                curCount=1;
            }
        }

        return cur;
    }
};