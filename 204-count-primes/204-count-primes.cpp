class Solution {
public:
    int countPrimes(int n) {
        
        vector<bool> primes(n+1);
        primes[0] = true;
        primes[1] = true;
        
        for(int i=2;i<=sqrt(n);i++)
        {
            if(!primes[i])
            {
                for(int j=i, k=2;j*k<=n;)
                {
                    if(j*k % i == 0)
                        primes[j*k] = true;
                    k++;
                }
            }
        }
        
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(!primes[i])
                count++;
        }
        
        return count;
    }
};