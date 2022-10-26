// class Solution {
// public:
//     bool issub(string s, string t, int m, int n)
//     {
//         if (m == 0)
//             return true;
//         if (n == 0)
//             return false;
 
    
//         if (s[m - 1] == t[n - 1])// If last characters of two strings are matching
//             return issub(s, t, m - 1, n - 1);
        
//         return issub(s, t, m, n - 1);// If last characters are not matching
// }
//     bool isSubsequence(string s, string t) {
//         int n = t.size();
//         int m = s.size();
//         if(issub(s, t, m, n))
//             return true;
//         return false;
        
//     }
// };


//using iterative
/*
class Solution {
public:
     bool isSubsequence(string s, string t) {
         int m = s.length();
         int n = t.length();
         int i=0, j=0;
         while(i<m && j<n)
         {
             if (s[i] == t[j])
                i++;
             j++;
         }
        if(i==m)
            return true;
         return false;
     }
};
*/


//Using LCS {dp}
// class Solution {
// public:
//     int lcs(string s1, string s2, int m, int n)
//     {
//         int dp[m+1][n+1];
//         for(int i = 0; i < m+1; i++)
//         {
//             for(int j = 0; j < n+1; j++)
//             {
//                 if(i == 0 || j == 0)
//                     dp[i][j] = 0;
//             }
//         }
//         for(int i = 1; i < m+1; i++)
//         {
//             for(int j = 1; j < n+1; j++)
//             {
//                 if(s1[i-1] == s2[j-1])
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 else
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//         return dp[m][n];
//     }
    
    
//      bool isSubsequence(string s, string t) {
//          int m = s.length();
//          int n = t.length();
//          int len = lcs(s, t, m, n);
//          if(m == 0)
//              return true;
//          if(n == 0)
//              return false;
//          if(len == min(m, n))
//              return true;
//          return false;
//      }
// };



class Solution {
public:
     bool isSubsequence(string s, string t) {
         int m = s.length();
         int n = t.length();
         int dp[m+1][n+1];
         for(int i = 0; i < m+1; i++)
         {
            for(int j = 0; j < n+1; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
             }
         }
         for(int i = 1; i < m+1; i++)
         {
            for(int j = 1; j < n+1; j++)
            {
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
             }
         }
        return dp[m][n] == m;
     }
};
