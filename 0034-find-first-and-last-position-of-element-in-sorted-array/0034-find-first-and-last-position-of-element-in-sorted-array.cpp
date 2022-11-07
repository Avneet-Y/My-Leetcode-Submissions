class Solution {
public:
    int firstoccur(int start, int end, vector<int>& nums, int target)
    {
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
        return res1;
    }
    
    int lastoccur(int start, int end, vector<int>& nums, int target)
    {
        int res2 = -1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(target == nums[mid])
            {
                res2 = mid;
                start = mid + 1;
            }
            else if(target > nums[mid])
                start = mid + 1;
            else if(target < nums[mid])
                end = mid - 1;   
        }
        return res2;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        //vector<int> vec(2);
        int n = nums.size();
        int resf = -1, resl = -1;
        resf = firstoccur(0, n - 1, nums, target);
        resl = lastoccur(0, n - 1, nums, target);
        return {resf, resl};
    }
};