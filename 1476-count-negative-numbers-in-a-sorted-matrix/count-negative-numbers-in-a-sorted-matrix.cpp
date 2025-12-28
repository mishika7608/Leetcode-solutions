class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c=0;
        int row=0,col=m-1;
        while (col>=0 && row<n){
            if (grid[row][col]<0){
                c+=n-row;
                col--;
            }
            else{
                row++;
            }
        }
        return c;
    }
};