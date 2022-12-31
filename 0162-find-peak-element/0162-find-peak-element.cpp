class Solution {
public:
    int solve(vector<int>& nums, int start, int end, int size)
    {
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(start == end)            //if size=1
                return start;
            if(mid > 0 && mid < size-1)
            {
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                {
                    return mid;
                }
                else if(nums[mid-1] > nums[mid])  //which is bigger go in that direction
                    end = mid-1;
                else
                    start = mid+1;
            }
            //to check last two elements edge
            else if(mid == 0)
            {
                if(nums[0]>nums[1])
                    return 0;
                else 
                    return 1;
            }
            else if(mid == size-1)
            {
                if(nums[size-1] > nums[size-2])
                    return size-1;
                else
                    return size-2;
            }    
        }
        return start;
    }
    
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int ans = solve(nums, 0, n-1, n);
        return ans;
    }
};