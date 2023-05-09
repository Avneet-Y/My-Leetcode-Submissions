class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int down = n-1;
        int left = 0;
        int right = m-1;
        int choice = 0;
        vector<int> ans;

        while(top <= down && left <= right)
        {
            if(choice == 0)
            {
                for(int i=left; i<=right; i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(choice == 1)
            {
                for(int i=top; i<=down; i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(choice == 2)
            {
                for(int i=right; i>=left; i--)
                {
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            else if(choice == 3)
            {
                for(int i=down; i>=top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            choice = (choice+1) % 4;
        }
        return ans; 
    }
};