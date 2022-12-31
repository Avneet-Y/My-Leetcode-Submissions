//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	//this is a question of Peak Element
	
	int solve(int arr[], int n, int start, int end)
	{
	    while(start <= end)
	    {
	        int mid = start + (end-start)/2;
	        if(mid > 0 && mid < n-1)
	        {
	            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
	                return arr[mid];
	            else if(arr[mid-1] > arr[mid])
	                end = mid - 1;
	            else
	                start = mid + 1;
	        }
	        else if(mid == 0)
	        {
	            if(arr[0] > arr[1])
	                return arr[0];
	            else
	                return arr[1];
	        }
	        else if(mid == n-1)
	        {
	            if(arr[n-1] > arr[n-2])
	                return arr[n-1];
	            else
	                return arr[n-2];
	        }
	    }
	    return arr[start];
	    
	}
	int findMaximum(int arr[], int n) {
	    // code here
	    int ans = solve(arr, n, 0, n-1);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends