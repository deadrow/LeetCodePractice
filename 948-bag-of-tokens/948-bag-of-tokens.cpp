class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        
        int start = 0;
        int end = tokens.size()-1;
        
        if(tokens.empty() || power < tokens[start])
            return 0;
        
        int score = 0;
        int maxScore = 0;
        while(start <= end)
        {
            if(score == 0 || power >= tokens[start])
            {
                power -= tokens[start++];
                score++;
            }
            else
            {
                power += tokens[end--];
                score--;
            }
            
            maxScore = max(maxScore , score);
        }
        
        return maxScore;
    }
    
};