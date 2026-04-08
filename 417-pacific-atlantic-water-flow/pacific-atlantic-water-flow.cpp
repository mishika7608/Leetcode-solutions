class Solution { 

public: 

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col){ 

        int rows = heights.size(); 

        int cols = heights[0].size(); 

        visited[row][col] = true; 

        int dr[4] = {-1, 1, 0, 0}; 

        int dc[4] = {0, 0, -1, 1}; 

        for(int k = 0; k < 4; k++){ 

            int r = row + dr[k]; 

            int c = col + dc[k]; 

            if(r >= 0 && r < rows && c >= 0 && c < cols  

               && !visited[r][c]  

               && heights[r][c] >= heights[row][col]){ 

                dfs(heights, visited, r, c); 

            } 

        } 

    } 

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) { 

        int rows = heights.size(); 

        int cols = heights[0].size(); 

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false)); 

        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false)); 

        // DFS from Pacific edges 

        for(int i=0;i<rows;i++) dfs(heights, pacific, i, 0); 

        for(int j=0;j<cols;j++) dfs(heights, pacific, 0, j); 

        // DFS from Atlantic edges 

        for(int i=0;i<rows;i++) dfs(heights, atlantic, i, cols-1); 

        for(int j=0;j<cols;j++) dfs(heights, atlantic, rows-1, j); 

        vector<vector<int>> result; 

        for(int i=0;i<rows;i++){ 

            for(int j=0;j<cols;j++){ 

                if(pacific[i][j] && atlantic[i][j]) 

                    result.push_back({i,j}); 

            } 

        } 

        return result; 

    } 

}; 