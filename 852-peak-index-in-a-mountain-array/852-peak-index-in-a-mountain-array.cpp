class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans, max = INT_MIN;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] > max)
                max = arr[i];
        }
        for(int i=0; i<arr.size(); i++)
        {
            if(max == arr[i])
                ans = i;
            
        }
    
        return ans;
    }
};