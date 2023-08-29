class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int j = s.length()-1;
        int count = 0;
        while(i <= j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                i++;
                count++;
            }
        }
        if(count <= 1)
        {
            return true;
        }

        count = 0;
        i = 0;
        j = s.length()-1;
        while(i <= j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                j--;
                count++;
            }
        }
        if(count <= 1)
        {
            return true;
        }
        return false;
    }
};