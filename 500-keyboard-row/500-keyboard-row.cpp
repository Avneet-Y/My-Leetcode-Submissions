class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string s[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        unordered_map<char, int> mp;
        for(int i = 0; i < 3; i++)
        {
            for(char ch : s[i])
            {
                mp[ch] = i;
                mp[ch - 'a' + 'A'] = i;
            }
        }
        for(auto it : words)
        {
            char c = it[0];
            bool flag = true;
            for(char ch : it)
            {
                if(mp[ch] != mp[c])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                ans.push_back(it);
        }
        return ans;
    }
};