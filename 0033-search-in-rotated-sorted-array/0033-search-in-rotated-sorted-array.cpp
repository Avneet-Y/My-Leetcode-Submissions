class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int mid = start + (end - start) / 2;
        while (start <= end)
        {
            if (nums[mid] == target)
            {
            return mid;
            }
            if (nums[0] <= nums[mid])
            {
                if (target >= nums[0] && target <= nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                if (target >= nums[mid] && target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            mid = start + (end - start) / 2;
        }
        return -1;
    }
};