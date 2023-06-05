class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i=0, j=0;
        int ans = 1;
        unordered_map<int, int> mp;
        if(n <= 2)
            return n;
        while(j<n)
        {
            mp[fruits[j]]++;
            if(mp[fruits[j]] == n)
                return n;
            if(mp.size() < 2)
            {
                j++;
            }
            if(mp.size() == 2)
            {
                ans = max(ans, j-i+1);
                j++;
            }
            
            if(mp.size() > 2)
            {
                while(mp.size() > 2)
                {
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0)
                        mp.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        
        return ans;
    }
};