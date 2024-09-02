class Solution {
public:
    vector<vector<long long>>memo;
    long long dp(vector<int>& energyDrinkA, vector<int>& energyDrinkB, bool fromA, int i){
        if(i>=energyDrinkA.size()) return 0;
        if(memo[i][fromA] != -1) return memo[i][fromA];
        long long take = (fromA ? energyDrinkA[i] : energyDrinkB[i]) + dp(energyDrinkA, energyDrinkB, fromA, i+1);
        long long change = (fromA ? energyDrinkA[i] : energyDrinkB[i]) + dp(energyDrinkA, energyDrinkB, !fromA, i+2);
        return memo[i][fromA]=max(take, change);
    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        memo.resize(energyDrinkA.size(), vector<long long>(2, -1));
        return max(dp(energyDrinkA, energyDrinkB, true, 0), dp(energyDrinkA, energyDrinkB, false, 0));
    }
};