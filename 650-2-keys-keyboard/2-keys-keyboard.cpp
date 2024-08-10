class Solution {
public:
    int INF = 1e5;
    int dp(int n, int curLetters, int lastCopied){
        if(curLetters > n) return INF;
        if(curLetters == n) return 0;
        int copy = 2 + dp(n, curLetters+curLetters, curLetters);
        int paste = 1 + dp(n, curLetters+lastCopied, lastCopied);
        return min(copy, paste);
    }
    int minSteps(int n) {
        if(n == 1) return 0;
        return dp(n, 1, 1)+1;
    }
};