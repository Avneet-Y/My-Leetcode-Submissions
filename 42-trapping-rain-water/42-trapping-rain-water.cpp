class Solution {
public:
    int trap(vector<int>& height) {
        
        int ans = 0;
        int n = height.size();
        
//         int lmax[n], rmax[n];
//         lmax[0] = height[0];
//         rmax[n-1] = height[n-1];
        
//         for(int i = 1; i<n ;i++)
//         {
//             lmax[i] = max(height[i], lmax[i-1]);
//         }
        
//         for(int i = n-2; i>=0 ;i--)
//         {
//             rmax[i] = max(height[i], rmax[i+1]);
//         }
        
//         for(int i=0; i<n; i++)
//             ans = ans + (min(lmax[i], rmax[i]) - height[i]);
            
//         return ans;
        
        int i=0;
        int j = n-1;
        
        int lmax=0,rmax=0;
        while(i <= j)
        {
            if(height[i] <= height[j])
            {
                if(height[i] >= lmax)
                    lmax = height[i];   
                else
                    ans += lmax - height[i];
                i++;
            } 
            else
            {
                if(height[j] >= rmax)
                    rmax = height[j];
                else
                    ans += rmax - height[j];
                j--;
            } 
        }
        return ans;
    }
};