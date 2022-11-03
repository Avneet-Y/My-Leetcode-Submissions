class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;
        int n = words.size();
        bool flag = false;
        
        for(auto i : words)
            mp[i]++;
        
        for(auto st : words)
        {
            string rev = st;
            reverse(st.begin(), st.end());
            
            if(rev != st && mp[rev]>0 && mp[st]>0) //lc!=cl, mp[lc] = 1, mp[cl] = 1;
            {
                mp[rev]--;                         //mp[lc]=0
                mp[st]--;                          //mp[cl] = 0
                ans += 4;                          // ans=lc+cl 
            }
            else if(rev == st && mp[st]>1)        //if xx,xx,xx given 
            {
                mp[rev] -= 2;                  //mp[xx] = 1 and  even no. wale hi push 
                ans += 4;                       //xxxx ans me pushed
            }
            else if(rev == st && mp[st]>0 && flag == false) //gg==gg, mp[gg]=1,(xx case ^)
            {
                mp[st]--;                          //mp[gg]=0,    mp[xx] =0
                ans += 2;                          //ans+=gg,     ans me xx push     
                flag = true;
            }
        }
        return ans;
    }
};