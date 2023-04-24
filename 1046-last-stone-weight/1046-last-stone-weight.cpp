class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> maxh;
        for(int i=0; i<n; i++)
        {
            maxh.push(stones[i]);
        }
        while(maxh.size() > 1)
        {
            int first = maxh.top();
            maxh.pop();
            int second = maxh.top();
            maxh.pop();
            int diff = first - second;
            maxh.push(diff);
        }
        return maxh.top();
    }
};