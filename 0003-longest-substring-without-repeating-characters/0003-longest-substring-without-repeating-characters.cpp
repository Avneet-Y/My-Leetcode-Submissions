class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int maxlen = -1;
        //set<int> s;
        unordered_map<char, int> mp;
        while(j < n)
        {
            mp[s[j]]++;

            if(mp.size() == j-i+1)
            {
                maxlen = max(maxlen, j-i+1);
                j++;
            }
            else if(mp.size() < j-i+1)
            {
                while(mp.size() < j-i+1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        if(n == 0)
            return 0;
        return maxlen;
    }
};