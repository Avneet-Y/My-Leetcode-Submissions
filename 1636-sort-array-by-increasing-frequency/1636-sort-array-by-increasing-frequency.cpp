// class Solution {
// public:
//    static bool comp(pair<int,int>&a, pair<int,int>&b)
//    {     // freq,ele ->pair
//       if(a.first == b.first)  //having same freq
//           return a.second > b.second;
     
//        return a.first < b.first;   //return having more freq
//    }
    
//     vector<int> frequencySort(vector<int> &nums) {
    
//         unordered_map<int,int>mp;    
//         for(auto i : nums)
//             mp[i]++;

//         vector<pair<int,int>> v;
    
//         for(auto i : mp)
//         {
//             v.push_back({i.second,i.first}); // frq , element
//         }
    
//         sort(v.begin(),v.end(),comp);
    
//         vector<int> ans;
    
//         for(int i=0; i<v.size(); i++)
//         {
//             while(v[i].first--)
//             {
//                 ans.push_back(v[i].second);
//             }
//         }
//      return ans;
//     }
// };




/*
class Solution {
public:
    
    vector<int> frequencySort(vector<int> &nums) {
    
        unordered_map<int,int>mp;    
        for(auto i : nums)
            mp[i]++;
        
        sort(nums.begin(), nums.end(), [&](int a, int b)
             {
                return mp[a] != mp[b] ? mp[a] < mp[b] : a > b; });

       
     return nums;
       
    }
};
*/


class Solution {
public:
    
    vector<int> frequencySort(vector<int> &nums) {

        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i=0; i<nums.size() ; i++)
        {
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int, int>> maxh;
        for(auto it : mp)
        {
            maxh.push({it.second, -1*(it.first)});
        }
        while(maxh.size() !=0 )
        {
            int freq = maxh.top().first;
            int ele = maxh.top().second;
            for(int i=1; i<=freq; i++)
            {
                ans.push_back(-1*(ele));
            }
            maxh.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};








