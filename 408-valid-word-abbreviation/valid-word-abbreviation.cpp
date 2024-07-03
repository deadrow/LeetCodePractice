class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i=0, j=0;
        int m= word.size();
        int n = abbr.size();
        while(i<m and j<n){
            if(word[i]==abbr[j]) i++,j++;
            else {
                if(isdigit(abbr[j]) and abbr[j] != '0'){
                    int num = 0;
                    while(isdigit(abbr[j])){
                        num *= 10;
                        num += abbr[j]-'0';
                        j++;
                    }
                    i += num;
                } else return false;
            }
        }

        return i==m and j==n;
    }
};