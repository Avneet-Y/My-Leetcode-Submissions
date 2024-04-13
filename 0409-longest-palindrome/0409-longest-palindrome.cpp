class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(auto it : s)
            mp[it]++;
        if(mp.size() == 1)
            return n;
        int oddct = 0;
        for(auto i : mp)
        {
            if(i.second % 2 == 1)
                oddct++;
        }
        if(oddct > 1)
            return n-oddct+1;
        else 
            return n;
        
    }
};