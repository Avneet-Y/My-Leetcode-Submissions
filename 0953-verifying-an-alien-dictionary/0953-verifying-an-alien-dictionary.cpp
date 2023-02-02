class Solution {
public:
    bool check(string s1, string s2, unordered_map<char, int> mp)
    {
        int i = 0;
        int j = 0;
        while(i < s1.size() && j < s2.size())
        {
            if(s1[i] != s2[j])
            {
                if(mp[s1[i]] < mp[s2[j]])
                    return true;
                else
                    return false;
            }
            i++;
            j++;
        }
        if(s1.size() <= s2.size())
            return true;
        return false;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        int weight = 1;
    
        for(auto it : order)
        {
            mp[it] = weight;
            weight++;
        }
        for(int i=0; i<words.size()-1; i++)
        {
            string first = words[i];
            string second = words[i+1];
            if(check(first, second, mp) == false)
                return false;
        }
        return true;
    }
};