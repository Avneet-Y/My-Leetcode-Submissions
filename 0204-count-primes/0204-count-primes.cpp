class Solution {
public:
    int countPrimes(int n) {
        bool prime[n+1];
        memset(prime, true, sizeof(prime));
        
        int ct = 0;
    
        for(int i=2; i*i < n; i++)
        {
            if(prime[i] == true)
            {
                for(int j = i*i; j<=n; j+=i)
                {
                    prime[j] = false;
                }
            }
        }
        for(int i = 2; i < n; i++)
        {
            if(prime[i] == true)
                ct++;
        }
        return ct;
        
    }
};