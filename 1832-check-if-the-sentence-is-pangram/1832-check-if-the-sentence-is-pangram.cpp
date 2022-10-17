class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>hash(26);
        
        int count = 0;
        for(int i=0;i<sentence.size();i++)
        {
            hash[sentence[i]-'a']++;
            if(hash[sentence[i]-'a'] == 1)
                count++;
        }
        
        return count >= 26;
    }
};