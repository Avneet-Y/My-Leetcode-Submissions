class Solution {
public:
    string breakPalindrome(string palindrome) {
        int start = 0;
        int end = palindrome.size() - 1;
        string st = "";
        
        if(palindrome.size() <= 1) 
            return st;
        while(start < end)
        {
            if(palindrome[start] != 'a' && palindrome[end] != 'a')
            {
                palindrome[start] = 'a';
                return palindrome;
            }
            else
            {
                start++; 
                end--;
            }
        }
        palindrome[palindrome.size() - 1] = 'b';
        return palindrome;
    } 
};