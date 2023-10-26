class Solution {
public:
    string customSortString(string order, string s) {
        int n1 = order.size();
        int n2 = s.size();
        string ans = "";
        map<char, int> mp;
        for(auto it : s)
            mp[it]++;
        for(int i=0; i<n1; i++)
        {
            char ele = order[i];
            if(mp.find(ele) != mp.end())
            {
                while(mp[ele]--)
                {
                    ans.push_back(ele);
                }
                mp.erase(ele);
            }
        }
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            char ele = it->first;
            int freq = it->second;
            for(int i=0; i<freq; i++)
            {
                ans += ele;
            }
            mp.erase(ele);
        }
        return ans;
    }
};