/*

class Solution {
public:
    int dp[2001][2001];
    bool ispalindrome(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string &s, int i, int j)
    {
        if(i >= j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int mini = INT_MAX; 
        
        if(ispalindrome(s, i, j) == true)
            return 0;
        
        for(int k = i; k <= j-1; k++)
        {
            if(ispalindrome(s, i, k) == true)
            {
                int tempans = solve(s, k+1, j) + 1;
                mini = min(mini, tempans);
                dp[i][j] = mini;
            }
        }
        return mini;
    }
    
    int minCut(string s) {
        int ans;
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        ans = solve(s, 0, n-1);
        return ans;
        
    }
};

*/

class Solution {
public:
    int dp[2001][2001];
    bool isPalindrome(string &s, int i, int j)
    {
        if(i == j)
            return true;
        while(i < j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string &s, int i, int j)
    {
        if(i >= j)
            return 0;
        if(isPalindrome(s, i, j) == true)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int mini = INT_MAX; 
        
        for(int k = i; k<= j-1; k++)
        {
            int tempans, left, right;
            
/*
Without checking if the left partition is a palindrome, the code will have TLE
calculate the right partition when the left part is palindromic.

because if the left is not palindromic, it will result in a deeper recursion call stack which is unnecessary because, all of such cases will be covered when the left is palindromic.

eg = "ayush", the minimum partition will be 5.
if you partition it into "a" and "yush" ( you calculate the right partition here)
then "y" and "ush" then "u" and "sh" and so on

but there is no point in calculating "ay" "ush" because if you think about it, it only result in a bigger recursion tree without fruitful results therefore this is done.
*/            
            if(isPalindrome(s, i, k) == true) 
            {
                right = solve(s, k+1, j);
            }
            
            tempans = 1 + right;
            
            if(tempans < mini)
            {
                mini = tempans;
            }
        }
        return dp[i][j] = mini;
    }

    
    int minCut(string s) {
        int ans;
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        ans = solve(s, 0, n-1);
        return ans;
        
    }
};