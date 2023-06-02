class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int i=0;
        int j=0;
        int ans = 0;
        unordered_map<char, int> mp;
        
        while(j<n)
        {
            mp[s[j]]++;
            if(j-i+1 < 3)
            {
                j++;
            }
            else if(j-i+1 == 3)
            {
                if(mp.size() == 3)
                    ans++;
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
                j++;
            }
        }
        return ans; 
        
    }
};