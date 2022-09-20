class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
     
        vector<int> vec(n2+1, 0);
        int ans = 0;
        
        for(int i = 0; i < n1; i++) 
        {
            for(int j = n2 - 1; j >= 0; j--) 
            {
                
                if (nums1[i] == nums2[j]) 
                {
                    vec[j + 1] = 1 + vec[j];
                } 
                else 
                {
                    vec[j + 1] = 0;
                }
                              
                ans = max(ans, vec[j + 1]);
            }   
        }
        return ans;
    }
};