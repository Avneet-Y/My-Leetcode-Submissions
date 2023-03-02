//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int n = s.size();
        int i = 0;
        int j = 0;
        int len = -1;
        unordered_map<char, int> mp;
        while(j < n)
        {
            mp[s[j]]++;
            if(mp.size() < k)
            {
                j++;
            }
            else if(mp.size() == k)
            {
                len = max(len, j-i+1);
                j++;
            }
            else if(mp.size() > k)
            {
                while(mp.size() > k)
                {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends