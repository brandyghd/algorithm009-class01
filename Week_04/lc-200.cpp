//200. 岛屿数量
class Solution {
public:
    int n;
    int m;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
        {
            return 0;
        }
        n = grid.size();
        m = grid[0].size();

        int j = 0;
        int count = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char> >& g,int i,int j)
    {
        if(i < 0 || i > n - 1 || j < 0 || j > m - 1 || g[i][j] == '0')
        {
            return;
        }
        g[i][j] = '0';
        dfs(g,i + 1,j);
        dfs(g,i - 1,j);
        dfs(g,i,j + 1);
        dfs(g,i,j - 1);
    }
};