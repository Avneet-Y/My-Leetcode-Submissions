class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int i=0, j=0;
        int ans = 0, count = 0;
        unordered_map<char, int> mp;
        
        while(j<n)
        {
            mp[s[j]]++;
            if(mp[s[j]] == k)
                count++;
            if(count == mp.size())
            {
                ans = max(ans, j-i+1);
            }
            j++;
            if(j == n)
            {
                mp.clear();
                i++;
                j = i;
                count=0;
            }  
        }
        return ans;
    }
};