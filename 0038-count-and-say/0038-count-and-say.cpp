class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        string curr;
        while(--n)
        {
            curr = "";
            for(int i=0; i<ans.size(); i++)
            {
                int count = 1;
                while(i < ans.size() - 1 && ans[i] == ans[i+1])
                {
                    count++;
                    i++;
                }
                curr +=  to_string(count) + ans[i] ;
            }
            ans = curr;
        }
        return ans;
        
    }
};