class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1 = s.size();
        unordered_map<char, int> mp1, mp2;
        
        for(int i=0; i<n1; i++)
            mp1[s[i]] = i+1;
        
        for(int i=0; i<n1; i++)
            mp2[t[i]] = i+1;
        
        for(int i=0; i<n1; i++)
        {
            if(mp1[s[i]] != mp2[t[i]])
                return false; 
        }
        return true;
    }
};