class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int del = 0;
        
        for(int j=0; j<m; j++)
        {
            string currentcol = "";
            for(int i=0; i<n; i++)
            {
                currentcol += strs[i][j];   
            }
            string revcol = currentcol;
            sort(currentcol.begin(), currentcol.end());
            if(currentcol != revcol)
                del++;
        }
        return del;
    }
};