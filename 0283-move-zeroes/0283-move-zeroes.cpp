class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int i=0, j=0;
        while(i<n)
        {
            if(nums[i] == 0)
            {
                i++;
            }
            else
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
        
    }
};