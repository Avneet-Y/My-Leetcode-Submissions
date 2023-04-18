class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n1 = word1.size();
        int n2 = word2.size();
        int i = 0;
        int j = 0;
        while(i < n1 && j < n2)
        {
            ans += word1[i];                
            i++;
            ans+= word2[j];
            j++;
        }
        if(n1 > n2)
        {
            while(i < n1)
            {
                ans+= word1[i];
                i++;
            }
        }
        if(n2 > n1)
        {
            while(j < n2)
            {
                ans+= word2[j];
                j++;
            }
        }
        return ans;
    }
};