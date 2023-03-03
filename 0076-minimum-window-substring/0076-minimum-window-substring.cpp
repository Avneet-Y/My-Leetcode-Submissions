class Solution {
public:
    string minWindow(string s, string t) {
        
        /*
        //showing TLE
        
        unordered_map<char, int> mp;
        int n1 = s.size();
        int n2 = t.size();
        for (int i = 0; i < n2; i++)
        {
            mp[t[i]]++;
        }
        int count = mp.size();
        string ans;

        int mini = INT_MAX;

        int i = 0;
        int j = 0;

        while (j < n1)
        {

            if (mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                {
                    count--;
                }
            }

            while (count == 0)
            {
                if (mini > j - i + 1)
                {
                    mini = min(mini, j - i + 1);
                    ans = s.substr(i, j - i + 1);
                }
                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if (mp[s[i]] == 1)
                    {
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
        return ans;
      */
        
        int n1 = s.size();
        int n2 =  t.size();
        
        int ans = INT_MAX;
        unordered_map<char, int> mp;
        for(auto it : t)
            mp[it]++;
        
        int count = mp.size();
        int start = 0; 
        
        int i = 0;
        int j = 0;
        while(j < n1)
        {
            mp[s[j]]--;
            if(mp[s[j]] == 0)
                count--;
            
            if(count == 0) //trying to minimize Win Size after getting a candidate for ans
            {
                while(count == 0)
                {
                    if (ans > j - i + 1)
                    {
                        ans = j - i + 1; //updating the answer
                        start = i;
                    }
                    
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                        count++;
                    i++;
                }
            }
            j++;
        }
        if(ans != INT_MAX) 
            return s.substr(start, ans);
        else
            return "";
   
    }
};