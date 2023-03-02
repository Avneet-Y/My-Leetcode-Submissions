//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    int n = s.size();
        int i = 0;
        int j = 0;
        int maxlen = -1;
        unordered_map<char, int> mp;
        while(j < n)
        {
            mp[s[j]]++;

            if(mp.size() == j-i+1)
            {
                maxlen = max(maxlen, j-i+1);
                j++;
            }
            else if(mp.size() < j-i+1)
            {
                while(mp.size() < j-i+1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        if(n == 0)
            return 0;
        return maxlen;
}