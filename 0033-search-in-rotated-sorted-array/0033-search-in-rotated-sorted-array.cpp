/*

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
*/


class Solution {
public:
    
    int Binsearch(vector<int> &nums, int start, int end, int target)
    {
        while(start <= end)
        {
            int mid = (start + end)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                end = mid - 1;
            else if(nums[mid] < target)
                start = mid + 1;
        }
        return -1;
    }
    
    
    int Mineleindex(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
       
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int prev = (mid+n-1) % n;
            int next = (mid+1) % n;
            if(nums[next] >= nums[mid] && nums[prev] >= nums[mid])
                return mid;
            if(nums[mid] <= nums[end])
                end = mid - 1;
            else if(nums[mid] >= nums[start])
                start = mid + 1;
        }
            return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int index = Mineleindex(nums);
            
        int lefttsearch = Binsearch(nums, 0, index-1, target);
        int rightsearch = Binsearch(nums, index, n-1, target);
        if(lefttsearch == -1)
            return rightsearch;
        else
            return lefttsearch;    
    }
};
