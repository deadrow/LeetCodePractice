class Solution {
public:
    vector<int>memo;
    bool dp(string& s, int i, int minJump, int maxJump){
        if(i>=s.size() or s[i] == '1') return false;
        if(i== s.size()-1) return true;
        if(memo[i] != -1) return memo[i];
        for(int j=minJump;j<=maxJump;j++){
            if(dp(s, i+j, minJump, maxJump)) return memo[i]=true;
        }
        return memo[i]=false;
    }
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.size()-1] == '1') return false;
        // eliminate cases where we get continuos 1s greater than maxJump
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '1'){
                count++;
                if(count>=maxJump) return false;
            } else count=0;
        }
        memo.resize(s.size(), -1);
        return dp(s, 0, minJump, maxJump);
    }
};