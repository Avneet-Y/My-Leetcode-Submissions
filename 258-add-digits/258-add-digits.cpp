class Solution {
public:
    int addDigits(int num) {
        // int ans;
        // if(num < 10)
        //     return num;
        // ans = addDigits(num/10) + (num%10);
        // if(ans<10)
        //     return ans;
        // return addDigits(ans/10) + (ans%10);
         if(num == 0)
            return 0; 
         else
             return(1 + (num - 1) % 9);
    }
};