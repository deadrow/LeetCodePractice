class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if(k == n)
            return totalSum;
        
        vector<int> prefixLeft(n+1);
        vector<int> prefixRight(n+1);
        
        for(int i=0;i<n;i++)
        {
            prefixLeft[i+1] = cardPoints[i] + prefixLeft[i];
            prefixRight[i+1] = cardPoints[n-i-1] + prefixRight[i];
        }
        
        int maxSum = 0;
        for(int i=0;i<=k;i++)
        {
            int curSum = prefixLeft[i] + prefixRight[k-i];
            maxSum = max(maxSum, curSum);
        }
        
        return maxSum;
    }
};