//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dp[501][501];
    bool isPalindrome(string s, int i, int j)
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
    
    int solve(string s, int i, int j)
    {
        if(i >= j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int mini = INT_MAX; 
        
        if(isPalindrome(s, i, j) == true)
            return 0;
        
        for(int k = i; k<= j-1; k++)
        {
            int tempans, left, right;
            if(dp[i][k] != -1)
            {
                left = dp[i][k];
            }
            else
            {
                left = solve(s, i , k);
                dp[i][k] = left;
            }
            
            if(dp[k+1][j] != -1)
            {
                right = dp[k+1][j];
            }
            else
            {
                right = solve(s, k+1 , j);
                dp[k+1][j] = right;
            }
            tempans = 1 + left + right;
            
            if(tempans < mini)
            {
                mini = tempans;
            }
        }
        return dp[i][j] = mini;
        
    }

    int palindromicPartition(string str)
    {
        int n = str.size();
        memset(dp, -1, sizeof(dp));
        int ans;
        ans = solve(str, 0, n-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends