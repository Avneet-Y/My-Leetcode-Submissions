class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;
        unordered_map<char, int> mp1, mp2;
        int n1 = s.size();
        int n2 = t.size();
        for(auto it : s)
            mp1[it]++;
        for(auto it : t)
            mp2[it]++;
        return mp1 == mp2;
        
    }
};