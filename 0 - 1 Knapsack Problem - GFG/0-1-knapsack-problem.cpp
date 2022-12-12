//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/*

class Solution
{
    public:
    int dp[1001][1001];
    //Function to return max value that can be put in knapsack of capacity W.
    int help(int cap, int wt[], int val[], int n)
    {
       // int profit;
        if(n == 0 || cap == 0)
        return 0;
        
        if(dp[n][cap] != -1)
        return dp[n][cap];
        
        else if(wt[n-1] <= cap)
        dp[n][cap] = max(val[n-1] + help(cap - wt[n-1], wt, val, n-1), help(cap, wt, val, n-1));
     
        else
        dp[n][cap] = help(cap, wt, val, n-1);
        
        return dp[n][cap];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
      
        memset(dp, -1, sizeof(dp));
        return help(W, wt, val, n);
    }
};
*/


/*

class Solution
{
    public:
    
    // //Function to return max value that can be put in knapsack of capacity W.
    // int help(int cap, int wt[], int val[], int n)
    // {
    //   // int profit;
    //     if(n == 0 || cap == 0)
    //     return 0;
        
    //     if(dp[n][cap] != -1)
    //     return dp[n][cap];
        
    //     else if(wt[n-1] <= cap)
    //     dp[n][cap] = max(val[n-1] + help(cap - wt[n-1], wt, val, n-1), help(cap, wt, val, n-1));
     
    //     else
    //     dp[n][cap] = help(cap, wt, val, n-1);
        
    //     return dp[n][cap];
    // }
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int dp[1001][1001];
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<W+1; j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j] = 0;

                }
            }
        }
        
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<W+1; j++)
            {
                if(j >= wt[i-1])
                {
                    dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]],  dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][W];
    }
};

*/
class Solution
{
    public:
    
    // //Function to return max value that can be put in knapsack of capacity W.
    // int help(int cap, int wt[], int val[], int n)
    // {
    //   // int profit;
    //     if(n == 0 || cap == 0)
    //     return 0;
        
    //     if(dp[n][cap] != -1)
    //     return dp[n][cap];
        
    //     else if(wt[n-1] <= cap)
    //     dp[n][cap] = max(val[n-1] + help(cap - wt[n-1], wt, val, n-1), help(cap, wt, val, n-1));
     
    //     else
    //     dp[n][cap] = help(cap, wt, val, n-1);
        
    //     return dp[n][cap];
    // }
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int dp[1001][1001];
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<W+1; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<W+1; j++)
            {
                if(wt[i-1]  <= j)
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][W];
    }
};







//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends