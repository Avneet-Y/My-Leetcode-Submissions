class Solution {
public:
    int xorOperation(int n, int start) {
        int xorele=0;
        int nums[n];
        
        for(int i=0; i<n; i++)
        {
            nums[i] = start + 2*i;   
        }
        
        for(int i=0; i<n; i++)
        {
            xorele = xorele ^ nums[i];
        }
        return xorele;
        
    }
};