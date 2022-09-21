class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=0;
        int j = arr.size()-1;
        int ans = j;
        while(i <= j)
        {
            int mid = i + (j-i)/2;
            if(arr[mid] > arr[mid+1] && arr[mid-1] < arr[mid])
                return mid;
            if(arr[mid] < arr[mid+1])
            {
                ans = mid;
                i = mid+1;
            }
            if(arr[mid] > arr[mid+1])
            {
                j = mid-1;
            }
        }
        return ans;
    }
};