class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int result = 0, total = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(satisfaction[i] + total < 0)
            {
                break;
            }
            else
            {
                total += satisfaction[i];
                result += total;
            }
        }
        return result;
    }
};