/*Here if the consecutive next element is greater than its element present just before  
then we can achieve max profit, like in eg 1 and in eg 2 ((2-1)+(3-2)+(4-3)+(5-4)) = 4
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 0;
        for(int i = 1; i < n; i++) 
        {
            if (prices[i] > prices[i - 1])
                buy += prices[i] - prices[i - 1];
        }
        return buy;
    }
};