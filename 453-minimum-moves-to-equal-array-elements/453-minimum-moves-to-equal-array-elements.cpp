class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = INT_MAX;
        for(auto it : nums)
            minNum = min(minNum, it);
        
        int moves=0;
        for(auto it : nums)
            moves += it-minNum;
        
        return moves;
    }
};