class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> left(n, 1);

        // left to right
        for(int i=1; i<n; i++) 
            if(ratings[i] > ratings[i-1]) left[i] = left[i-1]+1;

        int right=1;
        // right to left
        for(int i=n-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                right++;
                left[i] = max(left[i], right);
            }
            else right=1;
        }

        int ans=0;
        for(int i=0; i<n; i++) ans += left[i];

        return ans;

        
    }
};