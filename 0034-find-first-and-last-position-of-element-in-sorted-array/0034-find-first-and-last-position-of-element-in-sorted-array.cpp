class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //vector<int> vec(2);
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int res1 = -1;
        while(start <= end)
        {
           int mid = start + (end - start)/2;
            if(target == nums[mid])
            {
                res1 = mid;
                end = mid - 1;
            }
            else if(target > nums[mid])
                start = mid + 1;
            else if(target < nums[mid])
                end = mid - 1;   
        }
        int res2 = -1;
        start = 0, end = n - 1;
        
        while(start <= end) 
        {
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
            {
                res2 = mid;  
                start = mid + 1;    
            }
            else if(nums[mid] >= target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return {res1,res2};
    }
};