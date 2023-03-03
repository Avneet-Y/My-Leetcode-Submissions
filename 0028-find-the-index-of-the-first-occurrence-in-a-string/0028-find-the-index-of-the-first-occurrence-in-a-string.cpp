class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.size();
        int n2 = needle.size();
        int ind = -1;
        if(n2 > n1)
            return -1;
        for(int i=0; i <= n1-n2; i++)
        {
            string temp = haystack.substr(i, n2);
            if(temp == needle)
                return ind = i;
        }
        return ind;
    }
};