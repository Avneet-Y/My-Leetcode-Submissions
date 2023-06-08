//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lessthanmid(vector<int> &row, int middle)
    {
        int start = 0;
        int end = row.size()-1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(row[mid] <= middle)
                start = mid+1;
            else
                end = mid-1;
        }
        return start;
    }
    
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here         
        int n = R;
        int m = C;
        
        int start = 0;
        int end = 1e9;
        
        
        while(start<=end)
        {
            int middle = start + (end-start)/2;
            int count = 0;//how much less than mid
            for(int i=0; i<n; i++)
                count += lessthanmid(matrix[i], middle);
            
            if(count <= n*m/2)
                start = middle+1;
            else
                end = middle-1;
        }
        return start;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends