// class Solution {
// public:
//     bool wordPattern(string pattern, string s) {
         
//         int n = s.size(); 
//         unordered_map<char, string> mp1;
//         unordered_map<string, char> mp2;
//         int count = 0;   // store the no. of words in s
//         int k = 0;  //to character of pattern
//         int i = 0;
        
//         while(i < n)
//         {
//             string word = "";
//             while(i < n && s[i] != ' ')
//             {
//                 word += s[i];
//                 i++;
//             }
//             if(mp1.count(pattern[k]) && mp1[pattern[k]] != word)
//             {
//                 return false;       // if pattern[k] is mapped with more than one word
//             }
//             if(mp2.count(word) && mp2[word] != pattern[k])
//             {
//                 return false;       // if word is mapped with more than one char
//             } 
//             mp1[pattern[k]] = word;
//             mp2[word] = pattern[k];
//             count++;
//             k++;
//             i++;
//         }
//         if(count != pattern.size())
//             return false;
        
//         return true;
//     }
// };


class Solution {
public:
    bool wordPattern(string pattern, string s) {
         
        vector<string> vec;
        set<string> st;
        unordered_map<char, string> mp;
        int i = 0;
        int n = s.size();
        string word = "";
        while(i < n)
        {
            if(s[i] == ' ')
            {
                vec.push_back(word);
                word = "";
            }
            else
            {
                word += s[i];
            }
            i++;
        }
        
        vec.push_back(word);
        if(vec.size() != pattern.size())
            return false;
        
        for(int i = 0; i < pattern.size(); i++)
        {
            if(mp.find(pattern[i]) != mp.end())
            {
                if(mp[pattern[i]] != vec[i])
                    return false;
            }
            else
            {
                if(st.count(vec[i]) > 0)
                    return false;
                mp[pattern[i]] = vec[i];
                st.insert(vec[i]);
            }
        }
        return true;
        
    }
};