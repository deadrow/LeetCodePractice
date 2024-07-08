class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        long hash = 0;
        long powerk = 1;
        for(int i=0;i<k-1;i++)
            powerk = (power*powerk)%modulo;
        
        int end = s.size()-1;
        int idx = 0;
        int j=end;
        for(int i=end;i>=0;i--){
            long val1 = s[i]-'a'+1;
            hash = ((hash*power) + val1)% modulo;
            if(j-i+1 == k) {
                if(hash == hashValue)
                    idx = i;
                long val2 = hash-(s[j]-'a'+1);
                hash = (hash-(s[j]-'a'+1)*powerk%modulo + modulo)%modulo;
                j--;
            }
        }
        return s.substr(idx, k);
    }
};