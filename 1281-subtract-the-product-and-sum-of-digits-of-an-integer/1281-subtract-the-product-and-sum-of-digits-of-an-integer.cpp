class Solution {
public:
        
        int product(int n)
        {
            return (n < 10) ? n : n%10 * product(n/10);
        }
    
        int sum(int n)
        {
            return (n < 10) ? n : n%10 + sum(n/10);
        }
    
        int subtractProductAndSum(int n) 
        {
            return product(n) - sum(n); 
        // int pr = 1, sum = 0 , var;
        // while(n != 0)
        // {
        //     var = n%10;
        //     sum = sum + n % 10;
        //     n/=10;
        //     pr = pr*var;
        // }
        // return pr - sum;
        }
};