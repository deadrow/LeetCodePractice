class Solution {
public:
    unordered_map<int,int>mp;
    vector<vector<int>>memo;
    bool dfs(vector<int>& stones, int i, int k){
        if(i == stones.size()-1) return true;
        if(memo[i][k] != -1) return memo[i][k];
        for(int jump : {k-1, k, k+1}) {
            if(jump <= 0) continue;
            int nextPos = stones[i] + jump;
            if(mp.count(nextPos)) {
                if(dfs(stones, mp[nextPos], jump)) 
                    return memo[i][k] = true;
            }
        }

        return memo[i][k] = false;
    }
    bool canCross(vector<int>& stones) {
        memo.resize(3001,vector<int>(3001, -1));
        for(int i=0;i<stones.size();i++)
            mp[stones[i]] = i;
        return dfs(stones, 0, 0);
    }
};