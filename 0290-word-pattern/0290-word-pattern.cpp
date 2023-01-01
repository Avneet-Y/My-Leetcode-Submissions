class Solution {
public:
    bool wordPattern(string pattern, string s) {
         
        int n = s.size(); 
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        int count = 0;   // store the no. of words in s
        int k = 0;  //to character of pattern
        int i = 0;
        
        while(i < n)
        {
            string word = "";
            while(i < n && s[i] != ' ')
            {
                word += s[i];
                i++;
            }
            if(mp1.count(pattern[k]) && mp1[pattern[k]] != word)
            {
                return false;       // if pattern[k] is mapped with more than one word
            }
            if(mp2.count(word) && mp2[word] != pattern[k])
            {
                return false;       // if word is mapped with more than one char
            } 
            mp1[pattern[k]] = word;
            mp2[word] = pattern[k];
            count++;
            k++;
            i++;
        }
        if(count != pattern.size())
            return false;
        
        return true;
    }
};