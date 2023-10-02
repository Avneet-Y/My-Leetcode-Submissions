class Solution {
public:
     string lps(string s, int lt, int rt)
     {
        while(lt >= 0 && rt < s.size() && s[lt] == s[rt])
        {
            lt -= 1;
            rt += 1;
        }
        return s.substr(lt+1, rt-lt-1);
     }
    
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            string temp = lps(s, i, i);
            if(temp.size() > ans.size())
            {
                ans = temp;
            }
            temp = lps(s, i, i+1);
            if(temp.size() > ans.size())
            {
                ans = temp;
            }
        }
        return ans;
    }
};