//--
/*
class Solution {
public:
    
    int countSubstrings(string s) {
        int n = s.size();
        int dp[n][n];
        int ans = 0;
        for(int j = 0; j < n; j++)
        {
            for(int i = 0, k = j; i < n && k < n; i++, k++)
            {
                    if(i == k)
                    {
                        dp[i][k] = 1;
                    }
                    else if(abs(i-k) == 1)
                    {
                        if(s[i] == s[k]) 
                            dp[i][k] = 1;
                        else 
                            dp[i][k] = 0;
                    }
                    else
                    {
                        if(s[i] == s[k])
                        {
                            dp[i][k] = dp[i+1][k-1];
                        }
                        else
                        {
                            dp[i][k] = 0;
                        }
                    }
                ans += dp[i][k];
                }
        }
        return ans;
    }
};
*/


//Recursive
class Solution {
public:
    
    void countPalindrome(string s, int i , int j, int &count)
    {
        while(i >= 0 && j < s.length())
        {
            if(s[i] == s[j])
            {
                i--;
                j++;
                count++;
            }
            else 
                return;
        }
    }
    
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.length(); i++)
        {
            countPalindrome(s, i, i, count);
            countPalindrome(s, i, i+1, count);
        }
        return count;
    }
};