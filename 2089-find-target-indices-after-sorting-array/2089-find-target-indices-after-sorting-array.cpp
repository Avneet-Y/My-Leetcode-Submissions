class Solution {
public:
    int first(vector<int> &nums, int start, int end, int ele)
    {
        int res1 = -1;
        while(start <= end)
        {
            int mid = start + (end-start/2);
            if(ele == nums[mid])
            {
                res1 = mid;
                end = mid - 1;
            }
            else if(ele > nums[mid])
                start = mid+1;
            else
                end = mid - 1;
        }
        return res1;
    }
    int last(vector<int> &nums, int start, int end, int ele)
    {
        int res2 = -1;
        
        while(start <= end)
        {
            int mid = start + (end-start/2);
            if(ele == nums[mid])
            {
                res2 = mid;
                start = mid + 1;
            }   
            else if(ele > nums[mid])
                start = mid+1;
            else
                end = mid - 1;
        }
        return res2;
    }
    
    
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int fr = first(nums, 0, n-1, target);
        int lt = last(nums, 0, n-1, target);
        
        if(fr == -1 || lt == -1)
            return {};
        else if(fr == lt)
            ans.push_back(fr);
        else
        {
            for(int i = fr; i<= lt; i++)
                ans.push_back(i);
        }
        return ans;
                                                                                        
    }
};





                     




























// class Solution {
// public:
//      vector<int> ans;
//     void binary(vector <int> nums, int start, int end, int target)
//     {
//         if(start > end)       
//             return;
        
//         int mid = start + (end-start)/2;       
//         if(nums[mid] == target)
//         {                
//             binary(nums, start, mid-1, target);
//             ans.push_back(mid);
//             binary(nums, mid+1, end, target);      
//         }
//         else if(nums[mid]>target)               
//             binary(nums, start, mid-1, target);
//         else                                    
//             binary(nums, mid+1, end, target);
//     }
//     vector<int> targetIndices(vector<int>& nums, int target) {
        
//         sort(nums.begin(), nums.end());     
//         int start=0, end=nums.size()-1;
//         binary(nums, start, end, target);   
//         return ans;
//     }
// };