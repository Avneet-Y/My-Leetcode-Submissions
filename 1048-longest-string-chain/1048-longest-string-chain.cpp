class Solution {
public: 
    int length(string word, unordered_set<string>& st, unordered_map<string, int>& mp) {
        if (word.size() == 0) 
            return 0;
        if (mp.find(word) != mp.end()) 
            return mp[word];
        int ans = 0;
        for (int i = 0; i < word.size(); i++) 
        {
            string aux = word.substr(0, i) + word.substr(i + 1);
            if (st.find(aux) != st.end())
                ans = max(ans, 1 + length(aux, st, mp)); 
        }
        mp[word] = ans;
        return ans;
    }

    int longestStrChain(vector<string>& words) {
        unordered_set<string> st;
        for (string i : words)
            st.insert(i);
        int ans = 0;
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++) 
        {
            string str = words[i];
            ans = max(ans, length(str, st, mp));
        }
        return ans + 1;
    }
};