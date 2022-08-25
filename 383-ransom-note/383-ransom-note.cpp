class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       
//         int count[26] = {0};
        
//         for(auto i: magazine)
//             count[i - 'a']++;
        
//         for(auto i: ransomNote)
//         {
//             if(count[i - 'a']-- <= 0)
//                 return false;
//         }
//         return true;
        unordered_map<char , int >m;
        int count=0;
        for(int i=0 ; i<magazine.length() ; i++)
        {
            m[magazine[i]]++;
        }
        for(int i=0 ; i<ransomNote.size() ; i++)
        { 
            if(m[ransomNote[i]]==0) 
                return false;
            m[ransomNote[i]]--;
        }
        return true;
        
    }
};