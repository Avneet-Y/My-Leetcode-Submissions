class Solution {
public:
    int length(string s, int i, int j)
    {
        while(i >= 0 && j < s.size() && s[i] == s[j])
        {
            i--;
            j++;
        }
        return j-i-1;
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, end = 0;
        for(int i=0; i<n; i++)
        {
            int len1 = length(s, i, i+1);
            int len2 = length(s, i, i);
            int len = max(len1, len2);
            if(end < len)
            {
                start = i-(len-1)/2;
                end = len;
            }
        }
        return s.substr(start, end);
    }
};