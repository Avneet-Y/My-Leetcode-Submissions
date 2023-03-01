//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
         priority_queue<pair<int,int>> pq; 
   
        vector<int> ans;
    
        int j = 0, i = 0;
        
        while(j < n)
        {
        // add every element into the PQ
            pq.push({arr[j] , j});
            // window is not full... expand it
            if(j - i + 1 < k)
                j++;
            // window is full
            else if(j - i + 1 == k)
            {
                // remove the element not in the window from the PQ
                while(pq.top().second < i)
                    pq.pop();
                // push the max elemnet from the window into the PQ
                ans.push_back(pq.top().first);
                // slide the window
                i++; j++;
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends