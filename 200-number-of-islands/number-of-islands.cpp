//BFS
#include <queue>

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(!q.empty()){
                        auto [r,c]=q.front();
                        q.pop();
                        for(auto d:dir){
                            int nr=r+d.first;
                            int nc=c+d.second;
                            if(nr>=0 && nc>=0 && nr<rows && nc<cols && grid[nr][nc]=='1'){
                                grid[nr][nc]='0';
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};