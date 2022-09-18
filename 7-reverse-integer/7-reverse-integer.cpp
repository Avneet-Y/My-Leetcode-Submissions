class Solution {
public:
    int reverse(int x) {
        long  rev =0;
        while(x != 0)
        {
            rev = rev*10 + x%10;
            x/=10;
        }
       if(rev > 2147483641 || rev < -2147483641) 
           return 0;
        return rev;
        
    }
};