class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evensum = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] % 2 == 0) 
            {
                evensum += nums[i];
            }
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) 
        {
            int val = queries[i][0];
            int index = queries[i][1];
            if (nums[index] % 2 == 0) 
            {
                evensum -= nums[index];
            }
            nums[index] += val;
            if (nums[index] % 2 == 0) 
            {
                evensum += nums[index];
            }
            ans.push_back(evensum);
        }
        return ans;
    }
};