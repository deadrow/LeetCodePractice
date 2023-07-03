class Solution {
public:
    bool buddyStrings(string s, string goal) {
        vector<int> count(26);

        bool anyTwo = false;
        for(int i=0;i<s.size();i++)
        {
            count[s[i]- 'a']++;
            if(count[s[i]- 'a'] >=2)
                anyTwo = true;
        }
            
        for(int i=0;i<goal.size();i++)
            count[goal[i]- 'a']--;

        for(int i=0;i<26;i++)
        {
            if(count[i] != 0)
                return false;
        }

        if(s == goal)
            return anyTwo;

        int first_i = -1;
        int second_i = -1;
        for(int i=0;i<goal.size();i++)
        {
            if(goal[i] != s[i])
            {
                if(first_i == -1)
                    first_i = i;
                else if(second_i == -1)
                    second_i = i;
                else
                    return false;
            }
        }

        return true;
    }
};