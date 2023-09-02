//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
   int subset(vector<int>& A, int n, int subsetfind)
    {
        int dp[n+1][subsetfind+1];
        
        for(int i=0; i<n+1; i++)
        {
            //Because range of the sum includes 0. Eg - If all the elements are 0 and we want a sum 0, for that we need j from 0. So that 0 can also be considered as sum of previous subset of i elements.
            for(int j=0; j<subsetfind+1; j++) 
            {
                if(i == 0)
                    dp[i][j] = 0;
                if(j == 0)
                    dp[i][j] = 1;
            }
        } 
        
        for(int i=1; i<n+1; i++)
        {
            for(int j=0; j<subsetfind+1; j++)
            {
                if(A[i-1] <= j)
                    dp[i][j] = dp[i-1][j-A[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][subsetfind];
    }
    
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int n = A.size();
        int sum = 0;
        int subsetfind = 0;
        
        for(int i=0; i<n; i++)
        {
            sum += A[i];
        }
        if(sum < abs(target) || (target + sum) %2 != 0) 
               return 0;
        
        subsetfind = (sum+target)/2;
        int ans = subset(A, n, subsetfind);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends