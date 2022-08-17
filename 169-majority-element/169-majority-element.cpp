class Solution {
public:
    int majorityElement(vector<int>& nums) {
      // sort(nums.begin(),nums.end());
      // return nums[nums.size()/2];
        int ele;
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(count==0)
                ele = nums[i];
            
            if(ele == nums[i])
                count++;
            
            else
                count--;
        }
        return ele;
    }
};





