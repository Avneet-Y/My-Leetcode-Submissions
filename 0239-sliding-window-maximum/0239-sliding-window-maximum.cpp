class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//see compile error soln and prev soln why simple max heap not work priority queue  
        
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        
        int i = 0;
        int j = 0;
        while(j < n)
        {
            pq.push({nums[j], j});

            if(j-i+1 >= k)
            {
                while(pq.top().second <= j-k)      // while the topmost element is not present in k elements pop them and move forward
                {
                    pq.pop();
                    i++;
                }
                ans.push_back(pq.top().first);
            }
            j++;
        }
        return ans;
    }
};
