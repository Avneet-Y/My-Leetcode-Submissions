class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n1 = order.size();
        int n2 = words.size();
        unordered_map<char, int> mp;
        for(int i=0; i<n1; i++)
        {
            mp[order[i]] = i;
        }
        for(int i=0; i < n2-1; i++)
        {
            int j = 0;
            while(j < words[i].size() && j < words[i+1].size())
            {
               
                if(mp[words[i][j]] < mp[words[i+1][j]]) 
                    break;      //If words pair already sorted move to next pair
                if(mp[words[i][j]] > mp[words[i+1][j]])  //If they are not sorted 
                    return false;
                j++;
            }
            //for handling cases like Example 3
            if(j == words[i+1].size() && j < words[i].size()) 
                return false; 
            }
        return true;
        
        
//  map<char,int> mp;
//         bool res = true;
//         for(int i=0; i<order.size(); i++)
//              mp[order[i]] = i;
//         for(int i=0; i<words.size()-1; i++)
//         {
//             for(int j=0; j<words[i].size(); j++)
//             {
//                 if (j >= words[i + 1].length()) 
//                     return false;
//                  if(mp[words[i][j]]>mp[words[i+1][j]])
//                      return false;
//                  else if(mp[words[i][j]]<mp[words[i+1][j]]){
//                      break;
//                  }
                 
//             }
            
//         }
    }
};

        