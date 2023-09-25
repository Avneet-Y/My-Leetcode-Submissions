class Solution {
public:
    char findTheDifference(string s, string t) {
        //         unordered_map<char, int> um;
		
//         for(int i = 0; i < t.size(); i++)
//         {
// 			um[t[i]]++;
// 		}
// 		for(int i = 0; i < s.size(); i++)
//         {
// 			um[s[i]]--;
// 		}
// 		for(auto it = um.begin(); it != um.end(); it++)
//         {
// 			if(it->second == 1)
//             {
// 				return it->first;
// 			}
// 		}
// 		return 'a'; 
       
        char ans = t[s.size()];
		for(int i = 0; i < s.size(); i++)
        {
			ans ^= s[i] ^ t[i];
		}
		return ans;
        
    }
};