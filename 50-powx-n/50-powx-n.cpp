// class Solution {
// public:
 
//     double myPow(double x, int n)
//     {
//         double ans = 1;
//         if(n==0)
//             return 1;
//         else if(n < 0)
//         {
//             n = abs(n);
//             x = (1/x);
//         }
        
//         if(n%2 == 0)
//         {
//             return myPow(x*x, n/2);
        
//         }
//         else
//         {
//             return x*myPow(x*x, n/2);
//         }
//     }
    
// };


class Solution {
public:
 
    double myPow(double x, int n)
    {
        double ans = 1;
        if (n == INT_MAX) 
            return x;
        else if (n == INT_MIN)
        { 
             if(x == 1 || x == -1) 
                 return 1; 
            else 
                return 0;
        }
        else if(n < 0)
        {
            n = abs(n);
            x = (1/x);
        }
        
    for(int i=0;i<n;i++)
        ans = ans*x;
    
        return ans;
    }
};
        