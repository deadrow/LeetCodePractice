class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0;
        int j=0;

        int count = 0;
        int maxVowels = 0;
        string vowels = "aeiou";
        while(j < s.size())
        {
            if(s[j] == 'a' or s[j] == 'e' or s[j] == 'i' or s[j] == 'o' or s[j] == 'u')
                count++;

            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k)
            {
                maxVowels = max(count, maxVowels);
                if(maxVowels == k)
                    return maxVowels;
                if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
                    count--;
                j++;
                i++;
            }
        }

        return maxVowels;
    }
};