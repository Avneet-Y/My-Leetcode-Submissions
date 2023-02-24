class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int diff = INT_MAX;
        priority_queue<int> maxh;
        for(int i=0; i<n; i++)
        {
            if(nums[i]%2 == 1)
            {
                nums[i] *= 2;
            }
            mini = min(mini, nums[i]);
            maxh.push(nums[i]);
        }
        while(maxh.top() % 2 == 0)
        {
            int maxi = maxh.top();
            maxh.pop();
            diff = min(diff, maxi - mini);
            mini = min(mini, maxi/2);
            maxh.push(maxi/2);
        }
        return min(diff , maxh.top() - mini);
    }
};