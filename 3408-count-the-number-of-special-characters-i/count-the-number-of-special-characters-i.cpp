class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower=0,upper=0; // store data in bit
        for(char c : word){
            if(islower(c)) lower |= (1 << (c-'a'));
            else upper |= (1 << (c-'A'));
        }
        int count=0;
        for(int i=26;i>=0;i--)
            count += (lower & (1 << i)) and (upper & (1 << i));
        return count;
    }
};