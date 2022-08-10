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
                int first = arr[i];
                int second = arr[i]/arr[j];
                if(arr[i]%arr[j] == 0 && dict.find(second) != dict.end())
                {
                    dict[arr[i]] = (dict[arr[i]] + (dict[arr[j]]*dict[second]) % MOD)% MOD;
                }
            }
            
            total = (total + dict[arr[i]]) % MOD;
        }
        
//         long total = 0;
//         for(auto it : arr)
//         {
//             total +=dict[it];
//         }
        
        return total;
    }
};