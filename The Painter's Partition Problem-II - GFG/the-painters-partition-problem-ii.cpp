//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
   bool isvalid(int arr[], int n, int k, int mx)
    {
        int painter = 1;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            if(sum > mx)
            {
                painter++;
                sum = arr[i];
            }
            if(painter > k)
                return false;
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long ans = -1;
        long long sum = 0;
        int maxi = INT_MIN;
        // if(n < k)
        //     return -1;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            maxi = max(arr[i], maxi);
        }
        int start = maxi;
        long long end = sum;
        while(start <= end)
        {
            long long mid = start + (end-start)/2;
            if(isvalid(arr, n, k, mid) == true){
                ans = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
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