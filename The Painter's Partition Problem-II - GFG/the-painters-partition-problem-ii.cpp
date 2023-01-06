//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
    bool isvalid(int arr[], int n, int k, int mid)
    {
        long long sum = 0, paint = 1;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            if(sum > mid)
            {
                paint++;
                sum = arr[i];
            }
            if(paint > k)
                return false;
        }
        return true;
    }
  
    long long solve(int arr[], int n, int k )
    {
        int res = -1;
        int maxi = *max_element(arr, arr + n);
        int start = maxi;
        long long sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
        }
        long long end = sum;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(isvalid(arr, n, k, mid) == true)
            {
                res = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return res;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long ans = solve(arr, n, k);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends