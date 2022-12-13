//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
class Solution{
public:

    int dp[501][501];
    int solve(int arr[], int i, int j)
    {
        if(i >= j)
            return 0;
            
        int mini = INT_MAX;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        for(int k = i+1; k <= j; k++)
        {
            int tempans = solve(arr, i, k-1) + solve(arr, k, j) + arr[i-1]*arr[k-1]*arr[j];
        
            if(tempans < mini)
            {
                mini = tempans;
            }
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        int mincost;
        memset(dp, -1, sizeof(dp));
        mincost = solve(arr, 1, N-1);
        return mincost;
    }
};

*/










class Solution{
public:

    int dp[501][501];
    int solve(int A[], int i, int j)
    {
        if(i >= j)
          return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for(int k = i; k < j; k++)
        {
            int temp = solve(A, i, k) + solve(A, k+1, j) + A[i-1]*A[k]*A[j];
            if(temp < ans)
                ans = temp;
        }
        return dp[i][j] = ans;
    }
   
    int matrixMultiplication(int N, int arr[])
    {
        int sol;
        memset(dp, -1, sizeof(dp));
        sol = solve(arr, 1, N-1);
        return sol;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends