class Solution {
public:
    int maxindex(vector<vector<int>>& mat, int mid)
    {
        int index = 0;
        int maxind = INT_MIN;
        for(int i=0; i<mat[0].size(); i++)
        {
            if(mat[mid][i] > maxind)
            {
                maxind = mat[mid][i];
                index = i;
            }
        }
            return index;
    }
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int start = 0;
        int end = m-1;
        int ind = 0;
        
        while(start < end)
        {
            int mid = start + (end-start)/2;
            ind = maxindex(mat, mid);
            if(mat[mid+1][ind] < mat[mid][ind])
            {
                end = mid;  
            }
            else
            {
                start = mid+1;
            }
        }
        return {start, ind};
    }
};