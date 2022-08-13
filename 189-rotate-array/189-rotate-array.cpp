// class Solution {
// public:
//    void rotateByOne(vector<int> &nums)
//    {
// 		//TC = O(n*k)
//         int n = nums.size();
//         int temp = nums[n-1];
// 		for(int i=n-1; i>0; i--)
//         {
// 			nums[i] = nums[i-1];
// 		}
//         nums[0] = temp;
// 	}
//     void rotate(vector<int>& nums, int k) 
//     {
//         for(int i=0; i<k; i++) 
//             rotateByOne(nums);
//     }
// };


class Solution {
public:
    //TC = O(N)
   void rotateByOne(vector<int> &nums, int low, int high)
   {
        while(low < high)
        {
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
	}
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        k %= n;             // if k > n then the final result is the same as k%n
        rotateByOne(nums, n-k, n-1);
        rotateByOne(nums, 0, n-k-1);
        rotateByOne(nums, 0, n-1);
    }
};
