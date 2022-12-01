class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int ct1 = 0, ct2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(i < n/2)    
            {
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                    ct1++;
            }
            else 
            {
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                    ct2++;
            }
        }
        return ct1 == ct2;
        
    }
};