class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        /* Give TLE
        int n1 = s.size();
        int n2 = p.size();
        vector<int> ans;
        sort(p.begin(), p.end());
        for(int i=0; i <= n1-n2; i++)
        {
            string temp = s.substr(i, n2);
            sort(temp.begin(), temp.end());
            if(temp == p)
                ans.push_back(i);
        }
        */
        unordered_map<char , int> mp;
        
        for(auto it: p) 
            mp[it]++;
        int cnt = mp.size();
        int i = 0; 
        int j = 0;
        int k = p.size();
        
        vector<int> ans;
      
        while(j < s.size())
        {
            if(mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]] == 0) 
                    cnt--;
            }
             
            if(j-i+1 < k)   //when we don't hit the window
                j++;
             
            else if(j-i+1 == k)     //when hit the window
            {
                if(cnt == 0) 
                    ans.push_back(i);
                if(mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if(mp[s[i]] == 1)
                    {
                        cnt++;
                    }
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};