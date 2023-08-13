class Solution {
public:
    bool vowel(char c)
    {
        char ch = tolower(c);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false; 
    }
    
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        while(i <= j)
        {
            if(vowel(s[i]) == true && vowel(s[j]) == true)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(vowel(s[i]) == false)
            {
                i++;
            }
            else if(vowel(s[j]) == false)
            {
                j--;
            }
        }
        return s;
    }
};