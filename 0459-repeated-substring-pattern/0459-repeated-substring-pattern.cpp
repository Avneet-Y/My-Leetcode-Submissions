class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
         for(int i = n-1; i >= 0; i--)
         {
            if(i == 0) 
                return false;
            string temp = s.substr(0,i);
            if(s + temp == temp + s) 
                return true;
        }
        return false;
    }
};