class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;
        int n = words.size();
        bool flag = false;
        
        for(auto i : words)
            mp[i]++;
        
        for(auto st : words)
        {
            string rev = st;
            reverse(st.begin(), st.end());
            
            if(rev != st && mp[rev]>0 && mp[st]>0)
            {
                mp[rev]--;
                mp[st]--;
                ans += 4;
            }
            else if(rev == st && mp[st]>1)
            {
                mp[rev] -= 2;
                ans += 4;
            }
            else if(rev == st && mp[st]>0 && flag == false)
            {
                mp[st]--;
                ans += 2;
                flag = true;
            }
        }
        return ans;
    }
};