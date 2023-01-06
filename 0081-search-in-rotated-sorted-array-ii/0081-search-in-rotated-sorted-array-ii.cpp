class Solution {
public:
    
   bool search(vector<int>& nums, int start, int end, int target) 
    {
        while(start <= end)
        {
            int mid = start + (end-start) / 2;
            if(nums[mid] == target) 
                return true;
            
            // Additional part due to duplicate elemnets in  the array
            if(nums[start] == nums[mid] and nums[end]== nums[mid])
            {
                start++;
                end--;
            }   
            // check left side sorted or not
            else if(nums[mid] >= nums[start])
            {
                if(target >= nums[start] && target <= nums[mid]) // within range or not
                {
                    end = mid -1;
                }
                else
                    start = mid+1;
            }
            // right side sorted or not
            else
            {
                if(target >= nums[mid] && target <= nums[end])
                {
                    start = mid+1;
                }
                else
                    end = mid -1;
            }
        }
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();
        bool ans = search(nums, 0, n-1, target);
        return ans;
    }
};