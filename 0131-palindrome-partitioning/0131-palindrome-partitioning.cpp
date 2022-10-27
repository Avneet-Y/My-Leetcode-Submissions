class Solution {
public:
   bool isPalindrome(string &str)
    {
        for(int i=0; i<str.length()/2; i++)
        {
            if(str[i] != str[str.length()-i-1])
            {
                return false;
            }
        }
        return true;
    }
    void helper(string &str, int ind, vector<string> &curr, vector<vector<string>> &ans)
    {
        if(ind == str.length())
        {
            ans.push_back(curr);
            return;
        }
        string temp = "";
        for(int i=ind; i<str.length(); i++)
        {
            temp.push_back(str[i]);
            if(isPalindrome(temp))
            {
                curr.push_back(temp);
                helper(str,i+1, curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<string> curr;
        vector<vector<string>> ans;
        helper(s, 0, curr, ans);
        return ans;
        
    }
};