// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         int num = -1;
//         sort(nums.begin(),nums.end());
//         for(int i=1; i<n; i++)
//         {
//             if(nums[i] == nums[i-1])
//                 num = nums[i];
//         }
        
//     return num;
//     }
// };


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int slow = nums[0];  // both initialed as head i.e first
       int fast = nums[0];
        do
        {
            slow = nums[slow];    // move slow by 1
            fast = nums[nums[fast]];  // move fsst by 2
        }
        while(slow!=fast);   //unless they meet
        
        fast = nums[0];   //when they meet slow is meet pt fast is changed to first
        
        while(slow != fast)  
        {
            slow = nums[slow];   //now slow is moved by 1
            fast = nums[fast];   // fast is moved by 1
        }
    return slow;      // their intersection will show duplicate where cycle start
        }
};