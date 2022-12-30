
//O(n2)

// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int n = matrix[0].size();
//         int count = 0, ans;
//         for(int  i=0; i<n; i++)
//         {
//             for(int j=0; j<n ; j++)
//             {
//                 count++;
//             if(count == k)
//                 ans=matrix[i][j];
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix[0].size();
        priority_queue<int> ans; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
            {
                ans.push(matrix[i][j]);
                if(ans.size() > k)
                    ans.pop();
            }
        }
        return ans.top();   
    }
};