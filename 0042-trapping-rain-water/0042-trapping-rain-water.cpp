class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n];
        int right[n];
        left[0] = height[0];
        right[n-1] = height[n-1];
        int ans = 0;
        
        for(int i=1; i<n; i++)
        {
            left[i] = max(height[i], left[i-1]);
        }
        for(int i=n-2; i>=0; i--)
        {
            right[i] = max(right[i+1], height[i]);
        }
        for(int i=0; i<n; i++)
        {
            ans += (min(right[i], left[i])) - height[i];
        }
        return ans;
    }
};