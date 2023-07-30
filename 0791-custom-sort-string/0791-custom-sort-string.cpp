class Solution {
public:
    string customSortString(string order, string s) {
        int n1 = order.size();
        int n2 = s.size();
        map<char, int> mp;
        string ans = "";
        
        for(auto it : s)
            mp[it]++;
        
        for(auto it : order)
        {
            if(mp.find(it) != mp.end())
            {
                while(mp[it]--)
                {
                    ans.push_back(it);
                }
                mp.erase(it);
            }
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            char ele = it->first;
            int count = it->second;
            while(count--)
            {
                ans += ele;
            }
            mp.erase(ele);
        }
        return ans;   
        
    }
};