class Solution {
public:
    int countPrimes(int n) {
        
        vector<bool> primes(n+1, true);
        primes[0] = false;
        primes[1] = false;
        
        for(int i=2;i<=sqrt(n);i++)
        {
            if(primes[i])
            {
                for(int j=i, k=2;j*k<=n;)
                {
                    if(j*k % i == 0)
                        primes[j*k] = false;
                    k++;
                }
            }
        }
        
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(primes[i])
                count++;
        }
        
        return count;
    }
};