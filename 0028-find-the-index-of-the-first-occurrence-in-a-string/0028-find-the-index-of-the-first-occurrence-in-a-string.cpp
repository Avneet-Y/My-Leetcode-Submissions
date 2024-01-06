class Solution {
public:
    int strStr(string haystack, string needle) {
//         int n1 = haystack.size();
//         int n2 = needle.size();
//         if(n1 < n2)
//             return -1;
        
//         for(int i=0; i <= n1-n2; i++)
//         {
//             if(haystack.substr(i, n2) == needle)
//             {
//                 return i;
//             }
//         }
//         return -1;
      
        int n1 = haystack.size();
        int n2 = needle.size();
        for(int i=0; i<n1; i++)
        {
            int j = 0, ind = i;
            while(j<n2 && haystack[ind] == needle[j])
            {
                j++;
                ind++;
            }
            if(j == n2)
                return i;
        }
        return -1;
    }
    
};