class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            pq.push(nums[i]);
        }
        while(!pq.empty())
        {
            int ele = pq.top();
            pq.pop();
            ans.push_back(ele);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};