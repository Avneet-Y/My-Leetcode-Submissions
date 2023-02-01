class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        int n1 = str1.size();
        int n2 = str2.size();
    
        string ans = str2;
        int x = str2.size();
    
        while(x > 0)
        {  
            if(n2 % x != 0 || n1 % x != 0)
            {
                ans.pop_back();
                x--;
                continue;
            } 
            if((str1 + ans == ans + str1) && (str2 + ans == ans + str2))
            {
                return ans;
            }
            ans.pop_back();
            x--;
        }
        return "";
    }
};