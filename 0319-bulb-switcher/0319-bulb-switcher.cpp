class Solution {
public:
    int bulbSwitch(int n) {
    int ct = 0;
    for (int i = 1; i*i <= n; i++)
    {
        ct++;
    }
    return ct;
    }
};