class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int, int>> pq;
        vector<int> vec;
        int nowH;
        for (auto b:buildings) 
        {
            vec.push_back(b[0]);
            vec.push_back(b[1]);
        }
        sort(vec.begin(), vec.end());
        int m = unique(vec.begin(), vec.end()) - vec.begin();
        int j = 0, preH = 0;
        vector<vector<int>> ans;
        for (int i=0; i<m; i++) 
        {
            while (j<buildings.size() && buildings[j][0] <= vec[i]) 
            {   
                pq.push(make_pair(buildings[j][2], buildings[j][1]));
                j++;
            }
                while (!pq.empty() && pq.top().second <= vec[i]) 
                   pq.pop();
                if(pq.empty()) 
                    nowH = 0; 
                else 
                    nowH = pq.top().first;
            if (nowH != preH) 
            {
                ans.push_back({vec[i], nowH});
                preH = nowH;
            }
        }
        return ans;
    }
};