class Solution {
public:
    int isSubsquenece(string& word1, string& word2)
    {
        int m = word1.size();
        int n = word2.size();
        if(m + 1 != n)
            return false;
        
        int i=0;
        int j=0;
        while(i < m && j < n)
        {
            if(word1[i] == word2[j])
                i++;
            j++;
        }
        
        return i == m;
    }
    
    int longestStrChain(vector<string>& words) {
        
        // LOGIC
        // sort in increasing order of size
        // then apply LIS with one condition of subsequence check
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });
        
        vector<int> dp(words.size(),1);
        
        int ans = 1;
        for(int i=1;i<words.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isSubsquenece(words[j], words[i]))
                    dp[i] = max(dp[i], dp[j]+1);
            }
            
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};