class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        int i = n1-1;
        int j = n2-1;
        while(i >= 0 && j >= 0)
        {
            if(t[j] == s[i])
            {
                i--;
                j--;
            }
            else
                j--;
        }
        if(i < 0)
            return true;
        return false;
    }
};