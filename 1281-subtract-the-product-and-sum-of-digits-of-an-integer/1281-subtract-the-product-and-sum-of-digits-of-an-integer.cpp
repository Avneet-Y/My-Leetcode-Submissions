class Solution {
public:
    int subtractProductAndSum(int n) {
        int pr = 1, sum = 0 , var;
        while(n != 0)
        {
            var = n%10;
            sum = sum + n % 10;
            n/=10;
            pr = pr*var;
        }
        return pr - sum;
    }
};