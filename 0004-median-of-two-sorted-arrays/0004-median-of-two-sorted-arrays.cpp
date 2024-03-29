class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n = nums1.size();
        int m = nums2.size();
        
        int start = 0;
        int end = n;
        while(start <= end)
        {
            int mid1 = (start + end)/2;
            int mid2 = (n+m+1)/2 - mid1;
            
            int max1 = (mid1 == 0) ? INT_MIN : nums1[mid1-1];
            int max2 = (mid2 == 0) ? INT_MIN : nums2[mid2-1];
            int min1 = (mid1 == n) ? INT_MAX : nums1[mid1];
            int min2 = (mid2 == m) ? INT_MAX : nums2[mid2];
            
            if(max1 <= min2 && max2 <= min1)
            {
                if((n+m) % 2 == 0)
                {
                    return (max(max1, max2) + min(min1, min2)) / 2.0;
                }
                else
                {
                    return max(max1, max2);
                }
            }
            else if(max1 > min2)
            {
                end = mid1-1;
            }
            else
            {
                start = mid1+1;
            }
        }
        return 0.0;
        
    }
};