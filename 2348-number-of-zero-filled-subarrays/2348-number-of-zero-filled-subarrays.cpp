class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long total = 0;
        long long cnt = 0;

        long long n = nums.size();
        for(long long i=0; i<n; i++)
        {
            if(nums[i] == 0)
            {
                cnt++;
                total += cnt;
            }
            else
            {
                cnt = 0;
            }
        }
        return total;
    }
};