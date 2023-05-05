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
            if(vowels.find(s[j]) != string::npos)
                count++;

            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k)
            {
                maxVowels = max(count, maxVowels);
                if(vowels.find(s[i]) != string::npos)
                    count--;
                j++;
                i++;
            }
        }

        return maxVowels;
    }
};