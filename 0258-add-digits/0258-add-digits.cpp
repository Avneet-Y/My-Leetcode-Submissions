class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
        if(num == 0)
            return 0;
        if(num  % 9 == 0)
            return 9;
        ans = num%9;
        return ans;
    }
};