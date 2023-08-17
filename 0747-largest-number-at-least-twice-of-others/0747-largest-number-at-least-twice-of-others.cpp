class Solution {
public:
    int dominantIndex(vector<int>& nums) {
       int n=nums.size();
       vector<int> temp;
       temp = nums;
       sort(temp.begin(), temp.end());
       if(temp[n-2] * 2 <= temp[n-1])
       {
         for(int i=0; i<n; i++)
         {
           if(temp[n-1] == nums[i])
           {
               return i;
           }
         }
       }
       return -1;
    }
};