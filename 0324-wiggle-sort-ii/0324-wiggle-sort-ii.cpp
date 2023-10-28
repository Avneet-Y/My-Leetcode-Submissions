class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int start = (n-1)/2;
        int end = n-1;
        
        while(start >= 0)
        {
            ans.push_back(nums[start]);
                start--;
            
            if(end > (n-1)/2)
            {
                ans.push_back(nums[end]);
                end--;
            }
        }
        nums = ans;
    }
};