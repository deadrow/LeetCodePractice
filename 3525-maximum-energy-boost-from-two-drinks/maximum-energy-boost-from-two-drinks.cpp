class Solution {
public:
    vector<vector<long long>>memo;
    long long dp(vector<int>& energyDrinkA, vector<int>& energyDrinkB, bool fromA, int i){
        if(i>=energyDrinkA.size()) return 0;
        if(memo[i][fromA] != -1) return memo[i][fromA];
        long long take=0,change=0;
        if(fromA){
            take = energyDrinkA[i] + dp(energyDrinkA, energyDrinkB, fromA, i+1);
            change = energyDrinkA[i] + dp(energyDrinkA, energyDrinkB, !fromA, i+2);
        } else {
            take = energyDrinkB[i] + dp(energyDrinkA, energyDrinkB, fromA, i+1);
            change = energyDrinkB[i] + dp(energyDrinkA, energyDrinkB, !fromA, i+2);
        }
        return memo[i][fromA]=max(take, change);
    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        memo.resize(energyDrinkA.size(), vector<long long>(2, -1));
        return max(dp(energyDrinkA, energyDrinkB, true, 0), dp(energyDrinkA, energyDrinkB, false, 0));
    }
};