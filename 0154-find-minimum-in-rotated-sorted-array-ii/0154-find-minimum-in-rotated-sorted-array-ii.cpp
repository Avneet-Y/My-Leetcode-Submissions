class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        //This is also correct
        /*
        while (start < end) 
        {
            int mid = start + (end - start) / 2;
            int prev = (mid+n-1) % n;
            int next = (mid+1) % n;

            if (nums[mid] < nums[next] && nums[mid] < nums[prev])
            {
                return nums[mid];
            }
            if (nums[mid] == nums[start] && nums[mid] == nums[end]) 
            {
                start++;
                end--;
            } 
            else if(nums[end] >= nums[mid]) 
            { 
                end = mid ;
            } 
            else if(nums[mid] >= nums[start]) 
            {
                start = mid + 1;
            }
        }
        return nums[start];
        */
        while(start < end)
        {
            int mid = start + (end-start)/2;
            if(nums[end] == nums[mid])
            {
                end = end-1;   //linearly decreasing range from last
            }
            else if(nums[end] > nums[mid])
            {
                end = mid;
            }
            else if(nums[end] < nums[mid])
            {
                start = mid+1;
            }
        }
        return nums[start];
    }
};