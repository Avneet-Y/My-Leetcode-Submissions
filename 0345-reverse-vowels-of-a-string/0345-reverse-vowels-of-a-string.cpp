/*

class Solution {
public:
    string reverseVowels(string s) {
        
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j)
        {
            while(i<j)
            {
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                    break;
                if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                    break;
                i++;
            }
            while(i < j)
            {
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                    break;
                if(s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')
                    break; 
                j--;
            }
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};

*/


class Solution {
public:
    string reverseVowels(string s) {
        
        int i = 0;
        int j = s.size() - 1;
        unordered_set<char> st;
        st.insert({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        while(i < j)
        {
            while(!st.count(s[i]) && i < j)
            {
                i++;       
            }
            while(!st.count(s[j]) && i < j)
            {
                j--;       
            }
               swap(s[i], s[j]);
               i++;
               j--;
          
        }
               return s;
    }
};