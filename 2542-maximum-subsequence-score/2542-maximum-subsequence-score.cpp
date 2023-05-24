class Solution {
public:
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> vec;
        int n = nums1.size();
        for(int i=0; i<n; i++)
        {
            vec.push_back({nums2[i],nums1[i]});
        } 
        sort(vec.rbegin(), vec.rend());
        long long ans = 0;
        long long curr = 0;
        priority_queue<int,vector<int>,greater<int>> minh;
        int i = 0;
        while(i<n)
        {
            curr += vec[i].second;
            minh.push(vec[i].second);
            if(i >= k-1)
            {
                ans = max(ans, curr*vec[i].first);
                curr -= minh.top();
                minh.pop();
            }
            i++;
        }
        return ans;
    }
};