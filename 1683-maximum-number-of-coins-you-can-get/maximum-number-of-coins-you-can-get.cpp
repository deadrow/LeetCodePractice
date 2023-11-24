class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());

        int total = 0;
        int j = piles.size()-1;
        for(int i=1;i<=j;i+=2)
        {
            total += piles[i];
            j--;
        }

        return total;
    }
};