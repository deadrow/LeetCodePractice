class Solution {
public:
    int countPrimes(int n) {
        
        vector<bool> primes(n+1, true);
        primes[0] = false;
        primes[1] = false;
        
        int count = 0;
        for(int i=2;i<n;i++)
        {
            if(primes[i])
            {
                for(int j=i+i;j<=n; j+=i)
                {
                    primes[j] = false;
                }
                count++;
            }
        }
        
        // int count = 0;
        // for(int i=0;i<n;i++)
        // {
        //     if(primes[i])
        //         count++;
        // }
        
        return count;
    }
};