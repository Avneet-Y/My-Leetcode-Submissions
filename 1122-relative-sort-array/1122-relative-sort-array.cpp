class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        map<int, int> mp;
        vector<int> ans;
        for(auto it : arr1)
            mp[it]++;
        for(auto i=0; i<n2; i++)
        {
            int ele = arr2[i];
            if(mp.find(ele) != mp.end())
            {
                int freq = mp[ele];
                while(freq--)
                {
                    ans.push_back(ele);
                }
                mp.erase(ele);
            }
        }
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            int ele =it->first;
            int freq = it->second;
            while(freq--)
            {
                ans.push_back(ele);
            }
            mp.erase(ele);
        }
        return ans; 
    }
};