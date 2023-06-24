class Solution {
public:
    vector<vector<int>>memo;
    int MaxSum = 5001;
    int INF = 1 << 30;
    int solve(vector<int>& rods, int i, int leftSum, int rightSum)
    {
        if (i >= rods.size())
        {
            if(leftSum == rightSum)
                return 0;
            return -INF;
        }

        if(memo[i][leftSum-rightSum + MaxSum] != -1)
            return memo[i][leftSum-rightSum + MaxSum];
        // leave
        int leave = solve(rods, i+1, leftSum, rightSum);
        // add to left
        int toLeft = solve(rods, i+1, leftSum + rods[i], rightSum);
        // add to right
        int toRight = solve(rods, i+1, leftSum , rightSum + rods[i]);
        return memo[i][leftSum-rightSum + MaxSum] = max({leave, toLeft+rods[i], toRight+rods[i]});
    }

    int tallestBillboard(vector<int>& rods) {
        memo.resize(rods.size(), vector<int>(MaxSum*2, -1));
        return solve(rods, 0, 0, 0)/2;
    }
};