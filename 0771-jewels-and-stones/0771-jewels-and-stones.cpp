class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char, int> mp;
        int count = 0;
        for(auto i : stones)
            mp[i]++;
        for(char ch : jewels)
        {
            if(mp.find(ch) != mp.end())
            {
                count += mp[ch];
            }
        }
        return count;
    }
};