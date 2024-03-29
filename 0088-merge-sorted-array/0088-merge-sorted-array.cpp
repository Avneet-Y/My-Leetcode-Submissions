class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // for(int i=0; i<n; i++)
        // {
        //     nums1[i+m] = nums2[i];
        // }
        // sort(nums1.begin(), nums1.end());
        
        
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(j >= 0 && i >= 0)
        {
            if(nums2[j] > nums1[i])
            {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
            else if(nums1[i] >= nums2[j])
            {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
        }
        while(j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
        
    }
};