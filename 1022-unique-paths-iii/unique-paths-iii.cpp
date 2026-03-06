class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c, int remain) {
        int n = grid.size(), m = grid[0].size();

        if (r<0 || c<0 || r>=n || c>=m || grid[r][c] == -1)
            return 0;

        if (grid[r][c] == 2)
            return remain == 1;

        int temp = grid[r][c];
        grid[r][c] = -1; // mark visited

        int paths =
            dfs(grid, r+1, c, remain-1) +
            dfs(grid, r-1, c, remain-1) +
            dfs(grid, r, c+1, remain-1) +
            dfs(grid, r, c-1, remain-1);

        grid[r][c] = temp; // backtrack
        return paths;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int sr, sc, empty = 0;

        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j] == 0) empty++;
                if (grid[i][j] == 1){
                    sr = i;
                    sc = j;
                }
            }
        }

        return dfs(grid, sr, sc, empty + 2);
    }
};