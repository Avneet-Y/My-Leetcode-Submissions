class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> maxh;
        int sum = 0;
        for(int i = 0; i<n; i++)
        {
            maxh.push(piles[i]);
        }
        for(int i=0; i<k; i++)
        {
            int ele = maxh.top();
            maxh.pop();
            maxh.push(ele - (ele/2));
        }
        while(maxh.size() != 0)
        {
            sum += maxh.top();
            maxh.pop();
        }
        return sum;
        
    }                     
};