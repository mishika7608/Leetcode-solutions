class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j){
        if(dp[i][j] != 0) return dp[i][j];

        int rows = matrix.size();
        int cols = matrix[0].size();
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        int maxLen = 1; // path length including this cell
        for(auto &d : dirs){
            int ni = i + d[0], nj = j + d[1];
            if(ni>=0 && ni<rows && nj>=0 && nj<cols && matrix[ni][nj] > matrix[i][j]){
                maxLen = max(maxLen, 1 + dfs(matrix, dp, ni, nj));
            }
        }
        dp[i][j] = maxLen;
        return maxLen;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        int res = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        return res;
    }
};