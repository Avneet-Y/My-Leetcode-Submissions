class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

    int n = nums.size();
    int start = 0;
    int end = n - 2;
    while(start <= end)
    {
        int mid = start + (end - start)/2; 
        if(mid % 2 == 0) 
        {
            if(nums[mid+1] == nums[mid]) 
            {
                start = mid+1;   
            }
            else 
            {
                end = mid-1; 
            }
        }
        else
        {
            if(nums[mid+1] != nums[mid])
            {
                start = mid+1;
            }
            else 
            { 
                end = mid-1;
            }
        }
    }
    return nums[start];
    }
};