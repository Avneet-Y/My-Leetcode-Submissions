class Solution {
public:
     vector<int> ans;
    void binary(vector <int> nums, int start, int end, int target)
    {
        if(start > end)       
            return;
        
        int mid = start + (end-start)/2;       
        if(nums[mid] == target)
        {                
            binary(nums, start, mid-1, target);
            ans.push_back(mid);
            binary(nums, mid+1, end, target);      
        }
        else if(nums[mid]>target)               
            binary(nums, start, mid-1, target);
        else                                    
            binary(nums, mid+1, end, target);
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());     
        int start=0, end=nums.size()-1;
        binary(nums, start, end, target);   
        return ans;
    }
};