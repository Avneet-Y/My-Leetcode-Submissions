class Solution {
public:
    queue<pair<int, int>> q1;
	vector<vector<int>> visited;
	int bfs(vector<vector<char>> &grid, int i, int j, vector<vector<int>> visi)
	{
		int xn[] = {1, -1, 0, 0};
		int yn[] = {0, 0, -1, 1};
		queue<pair<int, int>> q;
		visited[i][j] = 1;
		q.push({i, j});
		q1.push({i, j});
		int ans = INT_MAX;
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i1 = 0; i1 < 4; i1++)
			{
				i = x + xn[i1];
				j = y + yn[i1];
				if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == '+' || visited[i][j] == 1)
					continue;
				visi[i][j] = visi[x][y] + 1;
				visited[i][j] = 1;
				q.push({i, j});
				q1.push({i, j});
				if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1)
					ans = min(visi[i][j], ans);
						}
		}
		if (ans == INT_MAX)
			return -1;
		else
			return ans - 1;
	}

public:
	int nearestExit(vector<vector<char>> &maze, vector<int> &e)
	{
		int i = e[0];
		int j = e[1];

		vector<vector<int>> visi;

		int xn[] = {1, -1, 0, 0};
		int yn[] = {0, 0, -1, 1};

		int n = maze.size();
		int m = maze[0].size();
		visited.resize(n + 1, vector<int>(m + 1, 0));

		visi.resize(n + 1, vector<int>(m + 1, 0));
		visi[i][j] = 1;
		return bfs(maze, i, j, visi);
        
    }
};