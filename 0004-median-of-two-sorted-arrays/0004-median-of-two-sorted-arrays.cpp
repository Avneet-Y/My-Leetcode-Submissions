class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double n1 = nums1.size();
        double n2 = nums2.size();
        vector<double> ans;
        
        for(int i=0; i<n1; i++)
        {
            ans.push_back(nums1[i]);
        }
        
        for(int i=0; i<n2; i++)
        {
            ans.push_back(nums2[i]);
        }
        sort(ans.begin(), ans.end());
        int n = ans.size();
        if(n % 2 == 0)
            return (ans[(n-1)/2]+ans[(n-1)/2 + 1])/2;
        else 
            return ans[n/2];
    }
};