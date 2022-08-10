class Solution {
public:
    const int MOD = 1000000007;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        unordered_map<int,long> dict;
        for(auto it : arr)
        {
            dict[it] = 1;
        }
        
        int n = arr.size();
        
        long total = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                // For big number we need to find all combination of
                // its factors. For eg [2,3,6,18]
                // for 6 count would be total ways to make 2 * total
                // ways to make 3
                int first = arr[i];
                int second = arr[i]/arr[j];
                if(arr[i]%arr[j] == 0 && dict.find(second) != dict.end())
                {
                    dict[arr[i]] = (dict[arr[i]] + (dict[arr[j]]*dict[second]) % MOD)% MOD;
                }
            }
            
            total = (total + dict[arr[i]]) % MOD;
        }
        
        return total;
    }
};