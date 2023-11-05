class Solution {
public:
    int getWinner(vector<int>& arr, int k) {

        int maxElem = arr[0];
        for(auto it : arr)
        {
            maxElem =  max(maxElem, it);
        }

        int curMax = arr[0];

        int wins = 0;
        for(int i = 1;i<arr.size();i++)
        {
            int newMax = max(curMax, arr[i]);
            if(newMax == curMax)
                wins++;
            else
            {
                curMax = newMax;
                wins = 1;
            }

            if(wins == k || curMax == maxElem)
                return curMax;
        }

        return -1;
    }
};