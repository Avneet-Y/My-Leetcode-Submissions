class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<n; i++)
        {
            pq.push({nums[i],i});
        }
       vector<int> ans;
       map<int, int> mp;
        while(k>0)
        {
            auto it = pq.top();
            mp[it.second] = it.first;
            pq.pop();
            k--;
        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans; 
    }
};