//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<pair<long long, long long>> st1, st2;
        vector<long long> left, right;
        // NSL
        long long pseudoindex = -1;
        for(int i=0; i<n; i++)
        {
            if(st1.size() == 0)
                left.push_back(pseudoindex);
            else if(st1.size() > 0 && st1.top().first < arr[i])
                left.push_back(st1.top().second);
            else if(st1.size() > 0 && st1.top().first >= arr[i])
            {
                while(st1.size() >0 && st1.top().first >= arr[i])
                {
                    st1.pop();
                }
                if(st1.size() == 0)
                    left.push_back(pseudoindex);
                else
                    left.push_back(st1.top().second);
            }
            st1.push({arr[i], i});
        }
        
        //NSR  
        pseudoindex = n;
        for(int i = n-1; i >= 0; i--)
        {
            if(st2.size() == 0)
                right.push_back(pseudoindex);
            else if(st2.size() > 0 && st2.top().first < arr[i])
                right.push_back(st2.top().second);
            else if(st2.size() > 0 && st2.top().first >= arr[i])
            {
                while(st2.size() > 0 && st2.top().first >= arr[i])
                {
                    st2.pop();
                }
                if(st2.size() == 0)
                    right.push_back(pseudoindex);
                else
                    right.push_back(st2.top().second);
            }
            st2.push({arr[i], i});
        }
        reverse(right.begin(), right.end());
        
        vector<long long> width(n);
        vector<long long> area(n);
        
        long long maxarea = INT_MIN;
        for(int i=0; i<n; i++)
        {
            width[i] = right[i] - left[i] - 1;
        }
        
        for(int i=0; i<n; i++)
        {
            area[i] = width[i] * arr[i];
            maxarea = max(maxarea, area[i]);
        }
        return maxarea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends