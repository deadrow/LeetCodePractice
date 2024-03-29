class Solution {
public:
    string breakPalindrome1(string palindrome) {
        int size = palindrome.size();
        
        if(size == 1)
            return "";
        
        set<string>ret;
        for(int i=0;i<size;i++)
        {
            string temp = palindrome;
            if(temp[i] > 'a')
            {
                temp[i] = 'a';
                string rev = temp;
                reverse(rev.begin(), rev.end());
                if(rev != temp)
                    return temp;
            }
        }
        
        palindrome[size-1] = 'b';
        return palindrome;
    }
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