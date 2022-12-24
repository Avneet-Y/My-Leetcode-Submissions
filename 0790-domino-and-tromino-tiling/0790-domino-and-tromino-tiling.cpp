class Solution {
public:
    int numTilings(int n) {
        vector<long long> dp(n+1,0);
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        if(n == 3)
            return 5;
        if(n <= 3)
        {
            return dp[n];
        }
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i=4; i <= n; i++) 
        {
            dp[i] = (2 * dp[i-1] + dp[i-3]) % 1000000007;
        }
        return dp[n];    
    }
};






/*
Thinking Process:
For n=1, the no. of ways = 1 and for n=2, the number of ways = 2. (obvious). 
For n=0, the number of ways = 1 and for -ve integers its 0.
Now,want to find out the number of ways for for n=3. attach a vertical domino at the end of all the different arrangements obtained for n=2 which would be 2. Then we can attach 2 horizontal bars at the end of all the arrangements obtained for n=1 which would be 1. And finally, 2 new patterns will be obtained if we consider the interlocking of two trominoes (which btw is only possible for n>=3). Hence, total no. of arrangements would be 2+1+2 = 5 which is indeed correct.
Similarly, for n=4, we can attach a vertical domino at the end of all the different arrangements obtained for n=3 which would be 5. Then we can attach 2 horizontal bars at the end of all the arrangements obtained for n=2 which would be 2. Then we can attach 2 interlocking trominoes(obtained initially at n=3) at the end of all the arrangements obtained for n=1 which would be 2. And finally, 2 new patterns will be obtained

see a pattern here.For any n, first we attach single vertical domino (which was initially obtained at n=1) with the arrangements obtained at n-1. then we attach two horizontal dominos(which was initially obtained at n=2) with the arrangements obtained at n-2. Then we attach the 2 new patterns obtained at n=3 with the with the arrangements obtained at n-3 and so on.

And, it we can see that every n>=3 creates two entirely new patterns. we can generate a recurrence relation:

dp[n] = dp[n-1] + dp[n-2] + 2dp[n-3] + 2dp[n-4] + ................. + 2*dp[0].

Now, this is a correct recurrence relation, but we can do better.
Substituting n for n-1, in the above relation, we obtain:

dp[n-1] = dp[n-2] + dp[n-3] + 2dp[n-4] + 2dp[n-5] + ................. + 2dp[0] + 2dp[-1].

We already assumed the answer to the negative integers to be 0. Hence it can be removed. Solving both equation we obtain:

dp[n] = 2*dp[i-3] + dp[i-3]
*/