class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        map<int, int> mp;
        
        vector<int> ans;
        
        for(auto it : arr1)
            mp[it]++;
        
        for(auto val : arr2)
        {
            if(mp.find(val) != mp.end())
            {
                while(mp[val]--)
                {
                    ans.push_back(val);
                }
                mp.erase(val);
            }
        }
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            int ele = it->first;
            int count = it->second;
            while(count--)
            {
                ans.push_back(ele);
            }
            mp.erase(ele);
        }
        return ans;     
    }
};