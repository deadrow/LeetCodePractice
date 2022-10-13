class Solution {
public:
    string breakPalindrome(string palindrome) {
        int size = palindrome.size();
        
        if(size == 1)
            return "";
        
        // it is pure greedy.
        // Just replace the first char greater than 'a'
        // if is it palindrome, discard it
        for(int i=0;i<size/2;i++)
        {
            if(palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        palindrome[size-1] = 'b';
        return palindrome;
    }
};