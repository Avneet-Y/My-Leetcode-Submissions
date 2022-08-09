class Solution {
public:
   static bool comp(pair<int,int>&a, pair<int,int>&b)
   {     // freq,ele ->pair
      if(a.first == b.first)  //having same freq
          return a.second > b.second;
     
       return a.first < b.first;   //return having more freq
   }
    
    vector<int> frequencySort(vector<int> &nums) {
    
        unordered_map<int,int>mp;    
        for(auto i : nums)
            mp[i]++;

        vector<pair<int,int>>v;
    
        for(auto i : mp)
        {
            v.push_back({i.second,i.first}); // frq , element
        }
    
        sort(v.begin(),v.end(),comp);
    
        vector<int> ans;
    
        for(int i=0; i<v.size(); i++)
        {
            while(v[i].first--)
            {
                ans.push_back(v[i].second);
            }
        }
     return ans;
    }
};




