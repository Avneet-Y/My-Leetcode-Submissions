class Solution {
public:
    vector<int> findcoord(int curVal , int n)
    {
        int row = n - (curVal - 1) / n - 1;
        int col = (curVal - 1) % n;
        if (row % 2 == n % 2) 
        {
            return {row, n - 1 - col};
        } 
        else 
        {
            return {row, col};
        }
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n  = board.size();
        int steps = 0;
        queue<int> q;
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        visited[n-1][0] = true;
        q.push(1);
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                int currnode = q.front();
                q.pop();
                if(currnode == n*n)
                    return steps;
                for(int diceval = 1; diceval <= 6; diceval++)
                {
                    if(diceval + currnode > n*n)
                        break;
                    vector<int> pos = findcoord(diceval + currnode, n);
                    int r = pos[0];
                    int c = pos[1];
                    if(visited[r][c] == true)
                        continue;
                    visited[r][c] = true;
                    if(board[r][c] == -1)
                        q.push(diceval + currnode);
                    else
                        q.push(board[r][c]);
                }
            }
            steps++;
        }
        return -1;
    }
};