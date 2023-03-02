class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        unordered_map<char,int>mp;
        // jo bhi char k se kam hai uspe aate hi apni string ka ans break ho jaayega 
        //eg a a a b b c d d a e a a f f    //a=6, b=2, d=2, c=1, e=1, f=2
       //    _ _ _ _ _ | _ _ _ | _ _ _ _
        //            
        //   |   =  yha ans break hoga
        //so calc freq of all and then ek pointer chalao jab tak vo invalid freq i.e 
        //whose freq less than k pe nhi pahunchta tab tak increment kro
        //jab vo invalid par pahunchega tab fir se usse pehle or uske bad ke pe
        //apna func chlao aur unme se max apna ans
         
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        int l = 0;
        while(l < n and mp[s[l]] >= k) 
            l++;
        if(l == n)  
            return n;
        

        int left = longestSubstring(s.substr(0, l), k);
        int right = longestSubstring(s.substr(l+1), k);

        return max(left,right);
        
        
        /* This is giving TLE
        
        int n = s.size();
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++)
            mp[s[i]]++;
        int start = 0;
        int maxlen = 0;
        bool valid = true;  //tell there is no valid char whose freq is less than k
        for(int end = 0; end < n; end++)
        {
            if(mp[s[end]] < k)
            {
                string temp = s.substr(start, end);
                maxlen = max(maxlen, longestSubstring(temp, k));
                start =  end+1;
                valid = false;
            }
            
        }
        if(valid == true)  // means no char in string where mp[s[end]] < k is met
            return n;
        else
            return max(maxlen, longestSubstring(s.substr(start), k));
            
            */
    }
};