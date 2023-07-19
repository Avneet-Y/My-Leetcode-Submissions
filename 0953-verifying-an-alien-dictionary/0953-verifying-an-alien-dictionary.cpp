class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
       vector<pair<string,string>> vec;
       unordered_map<char, char> mp;

       for(int i=0; i < order.size(); i++) 
           mp[order[i]] = char(i +'a');

       for(int i=0; i<words.size(); i++)
       {
           string temp;
           for(auto &it : words[i]) 
               temp.push_back(mp[it]);
           vec.push_back({temp, words[i]});
       }
        
       sort(vec.begin(), vec.end());

       for(int i=0; i<words.size(); i++)
           if(words[i] != vec[i].second) 
               return false;
    
       return true;
    }
};