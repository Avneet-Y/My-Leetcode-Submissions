class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int countgreater = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i % n] > nums[(i+1) % n])
            {
                countgreater++;
            }
        }
        if(countgreater <= 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};