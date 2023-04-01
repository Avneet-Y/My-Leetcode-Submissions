class Solution {
public:
    int binary(vector<int>& nums, int target, int n)
    {
        int start = 0;
        int end = n-1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(target == nums[mid])
            {
                return mid;
            }
            else if(target > nums[mid])
            {
                start = mid+1;
            }
            else 
                end = mid-1;
        }
        return -1; 
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = binary(nums, target, n);
        return ans;
    }
};