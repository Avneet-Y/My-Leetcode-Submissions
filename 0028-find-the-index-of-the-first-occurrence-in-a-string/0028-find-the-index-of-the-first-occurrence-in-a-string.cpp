class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.size();
        int n2 = needle.size();
        if(n1 < n2)
            return -1;
        
        for(int i=0; i <= n1-n2; i++)
        {
            if(haystack.substr(i, n2) == needle)
            {
                return i;
            }
        }
        return -1;
        
        
        
        
        
        // int haysize = haystack.size();
        // int needlesize = needle.size();
        // int ans = -1;
        // int ihay = 0, ineed = 0;
        // int jhay = haysize-1, jneed = needlesize-1;
        // while(ihay < haysize && jhay >= 0)
        // {
        //     if(haystack[ihay] != needle[ineed])
        //     {
        //         ihay++;
        //     }
        //     else if(haystack[ihay] == needle[ineed])
        //     {
        //         ans = ihay; 
        //         ihay++;
        //         ineed++;
        //     }
        // }
        
    }
};