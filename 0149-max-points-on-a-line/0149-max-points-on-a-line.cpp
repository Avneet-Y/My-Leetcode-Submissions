class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) 
            return n;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {

                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];    
                int total = 2;
                for(int k=0; k<n && k != i && k != j; k++)
                {    
                    int x = points[k][0];
                    int y = points[k][1];
                    if((y2 - y1)*(x - x1) == (x2 - x1)*(y - y1))
                        total++;
                }
                ans = max(ans, total);
            }
        }
        return ans;
    }
};