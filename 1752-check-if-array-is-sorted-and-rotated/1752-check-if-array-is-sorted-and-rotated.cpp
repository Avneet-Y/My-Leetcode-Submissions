class Solution {
public:
    bool check(vector<int>& nums) {
        int ct = 0, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i % n] > nums[(i + 1) % n])
            {
                if (ct == 1)
                    return false;
                ct++;
            }
        }
        return true;
    }
};