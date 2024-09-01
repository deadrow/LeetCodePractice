class Solution {
public:
    // TLE
    vector<int>memo;
    int dp(int x, int y){
        if(x <= 0) return INT_MAX-1;
        if(x == y) return 0;
        if(memo[x] != -1) return memo[x];
        int div_11 = INT_MAX-1;
        if(x % 11 == 0) div_11 = 1 + dp(x/11, y);
        int div_5 =INT_MAX-1;
        if(x % 5 == 0) div_5 = 1 + dp(x/5, y);
        int incr =INT_MAX-1;
        if(x-1>=0) incr = 1+dp(x-1, y);
        return memo[x]= min({div_11, div_5, incr, 1+dp(x+1, y)});
    }
    int minimumOperationsToMakeEqual1(int x, int y) {
        if(y>=x) return y-x;
        memo.resize(x+1000,-1);
        return dp(x, y);
    }
    int minimumOperationsToMakeEqual(int x, int y) {
        if(y>=x) return y-x;
        queue<pair<int,int>>bfs;
        bfs.push({x,0});
        unordered_set<int>visited;
        while(!bfs.empty()){
            auto cur = bfs.front();bfs.pop();
            int x = cur.first;
            if(visited.count(x)) continue;
            visited.insert(x);
            if(x==y) return cur.second;
            if(x % 11 == 0) bfs.push({x/11, cur.second+1});
            if(x % 5 == 0) bfs.push({x/5, cur.second+1});
            if(x-1>=0)
                bfs.push({x-1, cur.second+1});
            bfs.push({x+1, cur.second+1});
        }
        return -1;
    }
};