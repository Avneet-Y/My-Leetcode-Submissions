// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         int start = -1;
//         int next = 0;
//         int count = 0;
//         for(int i=0; next < n-1 ; i++)
//         {
//             if(i > start)
//             {
//                 count++;
//                 start = next;
//             }
//             next = max(next, nums[i]+i);
//         }
//         return count;
//     }
// };


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int far = 0;
        int count = 0;
        for(int i=0; i < n-1 ; i++)
        {
            far = max(far, nums[i]+i);
            if(i == curr)
            {
                curr = far;
                count++;
            }
        }
        return count;
    }
};