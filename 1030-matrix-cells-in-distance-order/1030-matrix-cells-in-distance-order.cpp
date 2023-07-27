class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
//         vector<vector<int>> ans;
// 		map<int,vector<vector<int>>> mp;
        
// 		for(int i=0; i<rows; i++)
//         {
// 			for(int j=0; j<cols; j++)
//             {
// 				int dis = abs(i - rCenter) + abs(j - cCenter);
// 				mp[dis].push_back({i,j});
// 			}
// 		}
// 		for(auto i : mp)
//         {
// 			for(auto j : i.second) 
//                 ans.push_back(j);
// 		}
// 		return ans;
        
        vector<vector<int>> ans;
        priority_queue<pair<int,vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int,vector<int>>> > pq;
        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                int dis = abs(rCenter - i) + abs(cCenter - j);
                vector<int> mat;
                mat.push_back(i);
                mat.push_back(j);
                pq.push({dis, mat});
            }
        }
        while(pq.size() > 0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};