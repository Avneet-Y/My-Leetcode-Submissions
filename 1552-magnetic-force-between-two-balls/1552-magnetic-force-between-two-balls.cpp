class Solution {
public:
    bool isvalid(vector<int>& position, int m, int n, int force)
    {
        int count = 1;
        int last = position[0];
        for(int i=0; i<n; i++)
        {
            if(position[i] - last >= force)
            {
                count++;
                if(count == m)
                    return true;
                last = position[i];
            }
        }
        return false;
    }
    
    int binary(vector<int>& position, int m, int n)
    {
        int start = 0;
        int end = position[n-1]; //since sorted so last will be maximum 
        int ans = -1;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(isvalid(position, m, n , mid) == true)
            {
                ans = mid;
                start = mid+1;
            }
            else
                end = mid-1;
        }
        return ans;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int ans = 0;
        ans = binary(position, m, n);
        return ans;
    }
};