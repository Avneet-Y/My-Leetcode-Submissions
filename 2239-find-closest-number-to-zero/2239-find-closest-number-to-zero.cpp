class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(),nums.end());
        // int close = INT_MAX;
        // for(int i=0; i<n; i++)
        // {
        //     if(abs(nums[i]) <= abs(close))
        //         close = nums[i];
        // }
        // return close;
        int mini = INT_MAX;
        int temp = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            if(abs(nums[i]) < mini)
            {   
                mini = abs(nums[i]);
                temp = nums[i];
            }
            else if(abs(nums[i]) == mini)
            {
                if(temp < nums[i])
                    temp = nums[i];
            }
        }
        return temp;
    }
};