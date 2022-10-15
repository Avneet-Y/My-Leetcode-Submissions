
int dp[101][27][101][101];
class Solution { 
public:
    string st;
    int solve(int index, int end, int len, int k)
    {
        if(k < 0)
            return INT_MAX / 2;
        if(index >= st.size())
            return 0;
        int &ans = dp[index][end][len][k];
        if(ans != -1)
            return ans;
        if(st[index] - 'a' == end)
        {
            int carry = (len == 1 || len == 9 || len == 99);
            ans = carry + solve(index+1, end, len+1, k);
        }
        else 
        {
            ans = min(1 + solve(index+1, st[index]-'a', 1, k), solve(index+1, end, len, k-1));
        }
        return ans;
    }
    int getLengthOfOptimalCompression(string str, int k) {
        st = str;
        memset(dp, -1, sizeof(dp));
        return solve(0, 26, 0, k);
    }
};