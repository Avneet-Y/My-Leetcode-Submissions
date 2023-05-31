class Solution {
public:
    // double recursion(double x, double n)
    // {
    //     if(x == 0)
    //         return 0;
    //     if(n == 0)
    //         return 1;
    //     return x * recursion(x, n-1);
    // }
    double myPow(double x, int n) {
         if (n == 0) 
             return 1.0;
        if (n % 2 == 0) 
            return myPow(x * x, n / 2);
        if (n % 2 == 1) 
            return x * myPow(x, n - 1);
        
        return 1/myPow(x, -n);
    }
};