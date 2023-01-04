class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size(); 
        unordered_map<int, int> mp;
        int count = 0;
        for(auto i : tasks)
        {
            mp[i]++;
        }
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(it->second == 1)
                return -1;
            count += ceil(it->second/3.0);
        }
        return count;
    }
}; 