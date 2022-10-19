//  here since greater in minheap won't return correct output as required in the question we need in lexicographical order so use comperator func to change the greater's property

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        priority_queue<pair<int, string>> minh;
        unordered_map<string, int> mp;
        for(auto i: words)
            mp[i]++;
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(minh.size() < k )
            {
                minh.push({-it->second, it->first});
            }
            else   //if minh == k
            {
                {
                    if(-minh.top().first < it->second)
                    {
                        minh.pop();
                        minh.push({-it->second, it->first});
                    }
                    else if(-minh.top().first == it->second && minh.top().second> it->first)
                    {
                        minh.pop();
                        minh.push({-it->second, it->first});
                    }
                }
            } 
        }
        
        while(minh.size() != 0)
        {
            ans.push_back(minh.top().second);
            minh.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

