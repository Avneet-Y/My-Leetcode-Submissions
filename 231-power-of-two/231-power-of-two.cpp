class Solution {
public:
    bool isPowerOfTwo(int n) {
        // while(n > 1) 
        // {
        //     if(n % 2)
        //         return false;
        //     n /= 2;
        // }
        // return n == 1;
        
        // if(n > 1) 
        //     while(n % 2 == 0)
        //     n /= 2;
        // return n == 1;
        
         if(n>0 && (n & (n-1))==0 )
            return true;
        return false;
        
        
        
    }
};