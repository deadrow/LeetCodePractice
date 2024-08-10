class Solution {
public:
    int INF = 1e5;
    vector<vector<int>>memo;
    int dp(int n, int curLetters, int lastCopied){
        if(curLetters > n) return INF;
        if(curLetters == n) return 0;
        if(memo[curLetters][lastCopied] != -1) return memo[curLetters][lastCopied];
        int copy = 2 + dp(n, curLetters+curLetters, curLetters);
        int paste = 1 + dp(n, curLetters+lastCopied, lastCopied);
        return memo[curLetters][lastCopied] = min(copy, paste);
    }
    int minSteps(int n) {
        if(n == 1) return 0;
        memo.resize(n+1, vector<int>(n+1, -1));
        return dp(n, 1, 1)+1;
    }
};