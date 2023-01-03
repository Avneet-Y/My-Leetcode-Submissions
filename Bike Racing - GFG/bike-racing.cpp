//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check(long H[], long A[], long L, long M, long mid, long n)
   {
       long current_speed=0;
       for(int i=0; i<n; i++)
       {
           long speed = H[i]+(mid*A[i]);
           if(speed >= L)
           current_speed += speed;
       }
       if(current_speed >= M)
        return true;
       else
        return false;
   }
   
   long buzzTime(long N, long M, long L, long H[], long A[])
   {
      long low = 0;
      long high = max(L,M);
      long ans=0;
      while(low <= high)
      {
          long mid = low + (high-low)/2;
          if(check(H, A, L, M, mid, N))
          {
              ans = mid;
              high = mid-1;
          }
          else
          {
              low = mid+1;
          }
      }
      
      return ans;
   }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends