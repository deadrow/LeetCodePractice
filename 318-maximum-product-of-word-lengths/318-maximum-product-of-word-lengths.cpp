class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxProduct = 0;
        
        vector<int> bitMasks;
        vector<int> lengths;
        
        for(int i=0;i<words.size();i++)
        {
            int bitMask = 0;
            for(auto it : words[i])
            {
                bitMask |= (1 << (it-97));
            }
            bitMasks.push_back(bitMask);
            lengths.push_back(words[i].length());
        }
        
        
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if((bitMasks[i] & bitMasks[j]) == 0)
                {
                    maxProduct = max(maxProduct, lengths[i]* lengths[j]);
                }
            }
        }
        
        return maxProduct;
    }
};