class Solution {
public:
     bool check(int x1,int y1,int x2,int y2,int x3,int y3)
     {
        return (x3-x2)*(y2-y1) == (x2-x1)*(y3-y2);
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        for(int i=2; i<n; i++)
        {
            int x1 = coordinates[i][0];
            int y1 = coordinates[i][1];
            int x2 = coordinates[i-1][0];
            int y2 = coordinates[i-1][1];
            int x3 = coordinates[i-2][0];
            int y3 = coordinates[i-2][1];
            if(!check(x1,y1,x2,y2,x3,y3))
                return false;
        }
        return true;
        
    }
};