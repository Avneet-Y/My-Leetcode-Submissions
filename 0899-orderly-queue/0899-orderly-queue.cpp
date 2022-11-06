class Solution {
public:
    string orderlyQueue(string s, int k) {
       
        if(k == 1)     //if this rotate the string and find the lexicographically min string
        {
            string ans = s;
            int n = s.length();
            for(int i = 0 ; i < n; i++)
            {
                char ch = s[n - 1];  // from last and add it to the front
                s.pop_back();
                s = ch + s;
                ans = min(s, ans);   
            }
            return ans;
        }
        sort(s.begin(), s.end());
        return s;
    }
};