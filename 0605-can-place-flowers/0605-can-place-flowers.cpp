class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int n = flowerbed.size();
        if(n == 1 && k == 1 && flowerbed[0] == 0)
        {
            return true;
        }
        for(int i=0; i < n && k; i++)
        {
            if(flowerbed[i] == 0)
            {
                if(i == 0)
                {
                    if(flowerbed[i + 1] == 0)
                    {
                        flowerbed[i] = 1;
                        
                        k--;
                    }
                }
                else if(i == n - 1)
                {
                    if(flowerbed[i - 1] == 0)
                    {
                        flowerbed[i] = 1;    
                        k--;
                    }
                }
                else
                {
                    if(flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                    {
                        flowerbed[i] = 1; 
                        k--;
                    }
                }
            }
        }
        return k == 0;
    }
};