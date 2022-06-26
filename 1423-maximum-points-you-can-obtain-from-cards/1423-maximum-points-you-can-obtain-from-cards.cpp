class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if(k == n)
            return totalSum;
        
        // find min sum of n-k in sliding window
        int i=0;
        int j=0;
        int curSum = 0;
        int minSum = totalSum;
        int windowSize = n-k;
        while(j < n)
        {
            curSum += cardPoints[j];
            if(j-i+1 < windowSize)
                j++;
            else if(j-i+1 == windowSize)
            {
                minSum = min(minSum, curSum);
                curSum -= cardPoints[i];
                i++;
                j++;
            }
        }
        
        return totalSum - minSum;
    }
};