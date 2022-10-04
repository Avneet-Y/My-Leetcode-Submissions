class Solution {
public:
    int countPoints(string rings) {
        int r[10] = {0};
        int g[10] = {0};
        int b[10] = {0};
    
        int rod;
        for(int i=0; i<rings.size(); i+=2)
        {
            rod = rings[i+1]-'0';
            if(rings[i] == 'R')
            {
                r[rod]++;
            }
            else if(rings[i] == 'G')
            {
                g[rod]++;
            }
            else if(rings[i] == 'B')
            {
                b[rod]++;
            }
        }
        int count=0;
        for(int j=0; j<10; j++)
        {
            if(r[j] > 0 && g[j] > 0 && b[j] > 0)
            {
                count++;
            }
        }
    
        return count;
    }
};