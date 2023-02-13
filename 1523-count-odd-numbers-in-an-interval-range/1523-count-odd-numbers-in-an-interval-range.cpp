class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        count = (high - low) / 2;
        if(low % 2 != 0 || high % 2 != 0)   //if one of them is odd like ex 1 7-3/2=2 but +1
        {
            count++;
        }
        return count;
    }
};