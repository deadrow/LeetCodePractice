class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i=0,j=0;
        while(i<word.size() and j<abbr.size()){
            if(isdigit(abbr[j]) and abbr[j]!='0'){
                int num=0;
                while(isdigit(abbr[j])){
                    num = num*10 + abbr[j]-'0';
                    j++;
                }
                i += num;
            } else if(word[i] != abbr[j]) return false;
            else { i++,j++;}
        }
        return i==word.size() and j==abbr.size();
    }
};