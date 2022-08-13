/* 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec;
        int square = 0;
        for(int i=0;i<n;i++)
        {
            square = nums[i]*nums[i];
            vec.push_back(square);
        }
        sort(vec.begin(),vec.end()); //nlogn
        return vec;
    }
};
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n);
        int start=0, last=n-1;
        for(int i=n-1; i>=0; i--)
        {
            if(abs(nums[last] > abs(nums[start])))
            {
                vec[i] = nums[last] * nums[last];
                last--;
            }
            else
            {
                vec[i] = nums[start] * nums[start];
                start++;
            }
        }
        return vec;
    }
};

