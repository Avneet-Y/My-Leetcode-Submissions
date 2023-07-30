//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string, int> mp;
        for(int i=0; i<n; i++)
            mp[arr[i]]++;
            
        int maxvote = 0;
        string name;
        vector<string> ans;
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(it->second > maxvote)
            {
                maxvote = it->second;
                name = it->first;
            }
            else if(it->second == maxvote)
            {
                if(it->first < name)
                    name = it->first;
            }
        }
        
        ans.push_back(name);
        string temp = to_string(maxvote);
        ans.push_back(temp);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends