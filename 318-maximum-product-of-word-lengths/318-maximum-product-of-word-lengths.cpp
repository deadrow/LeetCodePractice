class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxProduct = 0;
        
        for(int i=0;i<words.size();i++)
        {
            string first = words[i];
            vector<int>table(26);
            for(auto it : first)
            {
                table[it-97]++;
            }
            
            for(int j=i+1;j<words.size();j++)
            {
                string second = words[j];

                bool exists = false;
                for(auto it : second)
                {
                    if(table[it-97] != 0)
                    {
                        exists = true;
                        break;
                    }
                }
                
                if(!exists)
                {
                    int cur = first.length()*second.length();
                    maxProduct = max(maxProduct, cur);
                }
            }
        }
        
        return maxProduct;
    }
};