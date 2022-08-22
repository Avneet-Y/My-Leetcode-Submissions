class Solution {
public:
    bool isPowerOfFour(int n) {
        
        // while(n > 1) 
        // {
        //     if(n % 4)
        //         return false;
        //     n /= 4;
        // }
        // return n == 1;
        
        if(n>0 && (n & (n-1))==0 && (n-1)%3==0)
            return true;
        return false;
        
        
    }
};