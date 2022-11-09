class Solution {
public:
    int findMin(vector<int>& nums) {
        
//         int n = nums.size();
    
//         if(n == 1)
//             return nums[0];
        
//         if(nums[0] < nums[n-1])
//             return nums[0];
        
//         int start = 0;
//         int end = n-1;
        
//         int ans = INT_MAX;
//         while(start <= end)
//         {    
//             int mid = (start + end) / 2;
			
//             if(nums[mid] >= nums[0])
//                 start = mid +1;
            
//             else
//             {
//                 ans = min(ans , nums[mid]);
//                 end = mid - 1;
//             }
//         }
//         return ans;
        
        
        int start = 0;
        int n = nums.size();
        int end = n - 1, next, prev;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[start] <= nums[end])
                return nums[start];
            next = (mid + 1) % n;
            prev = (mid + n - 1) % n;
            if(nums[mid] <= nums[next] && nums[mid] <= nums[prev])
                return nums[mid];
            else if(nums[start] <= nums[mid])
                start = mid + 1;
            else if(nums[mid] <= nums[end])
                end = mid - 1;
        }
        return nums[start];
    }
};