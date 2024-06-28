class Solution {
public:
    vector<int>balances;
    int dfs(int cur_i){
        if(cur_i >= balances.size()) return 0;
        if(balances[cur_i] == 0)
            return dfs(cur_i+1);

        int minVal = INT_MAX;
        int curBalance = balances[cur_i];
        for(int i = cur_i+1;i<balances.size();i++){
            int nextBalance = balances[i];
            if(curBalance*nextBalance < 0){
                balances[i] = curBalance+nextBalance;
                minVal = min(minVal, 1+dfs(cur_i+1));
                balances[i] = nextBalance;
            }
        }
        return minVal < INT_MAX ? minVal : 0;
    }
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int,int>balanceDict;
        for(auto it : transactions){
            balanceDict[it[0]] -= it[2];
            balanceDict[it[1]] += it[2];
        }

        for(auto it : balanceDict) {
            cout << it.second << " ";
            if(it.second)
                balances.push_back(it.second);
        }
            

        return dfs(0);
    }
};