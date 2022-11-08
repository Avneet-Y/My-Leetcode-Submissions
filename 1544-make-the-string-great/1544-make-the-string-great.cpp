class Solution {
public:
    string makeGood(string s) {
        int start = 0;
        while(start != s.size())
        {
            start = s.size();
            for(int i = 0; i < s.size(); i++)
            {
              if(s[i]+32 == s[i+1] or s[i+1]+32 == s[i])
                s.erase(i, 2);
            }
        }
        return s;
    }
};