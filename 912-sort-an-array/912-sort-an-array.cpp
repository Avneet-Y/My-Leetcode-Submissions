class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // return nums;
        
//         priority_queue<int> pq;
//         vector<int> ans;
//         for(int i=0; i<nums.size(); i++)
//         {
//             pq.push(nums[i]);
//         }
        
//         while(pq.size()!=0)
//         {
//             ans.push_back(pq.top());
//             pq.pop();
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
        
        priority_queue<int, vector<int>, greater<int>> minheap;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            minheap.push(nums[i]);
        }
        
        while(minheap.size()!=0)
        {
            ans.push_back(minheap.top());
            minheap.pop();
        }
        return ans;
        
    }
};