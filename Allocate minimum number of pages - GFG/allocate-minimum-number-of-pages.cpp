//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool isvalid(int A[], int N, int M, int maxi)
    {
        int tempsum = 0, student = 1;
        for(int i=0; i<N; i++)
        {
            tempsum += A[i];
            if(tempsum > maxi)
            {
                student++;
                tempsum = A[i];
            }
            if(student > M)
                return false;
        }
        return true;
    }
    
    int solve(int A[], int N, int M)
    {
        int maxi = INT_MIN;
        int sum = 0, res = -1;
        for(int i=0; i<N; i++)
        {
            maxi = max(maxi, A[i]);
            sum += A[i];
        } 
        int start = maxi;
        int end = sum;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(isvalid(A, N, M, mid) == true)   //can be possible ans but on left side we can find also
            {
                res = mid;
                end = mid-1;
            }
            else 
            {
                start = mid + 1;    //not satisfy means we can make it bigger 
            }
        }
        return res;
    }
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        int ans = solve(A, N, M);
        if(M > N)
            return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends