//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool isvalid(vector<int> &stations, int n, int k, double mid)
    {
        int count = 0;
        double dis = 0;
        for(int i=1; i<n; i++)
        {
            int temp = stations[i] - stations[i-1];
            dis = (double)temp/mid;
            count += (int(dis));
        }
        if(count <= k) 
            return true;
        return false;
    }
  
    double solve(vector<int> &stations, int n, int k)
    {
        double start = 0;
        double end = stations[n-1] - stations[0];
        double res = end;
        while(end - start > 1e-6)
        {
            double mid = start + (end-start)/2;
            if(isvalid(stations, n, k, mid) == true)
            {
                end = mid;
                res = mid;
            }
            else
                start = mid;
        }
        return res;
    }
    
    
    double findSmallestMaxDist(vector<int> &stations, int k){
      // Code here
      int n = stations.size();
      sort(stations.begin(), stations.end());
      double ans = solve(stations, n, k);
      return ans;
    }
};




//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends