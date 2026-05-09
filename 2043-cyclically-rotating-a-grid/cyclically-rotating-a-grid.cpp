class Solution {
public:

    void rotatekpos(vector<int>& vec, int k) {
        k %= vec.size();
        // left rotate by k
        rotate(vec.begin(), vec.begin() + k, vec.end());
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> spiral;

        int t = 0, l = 0;
        int b = n - 1, r = m - 1;

        // extract all layers
        while (l < r && t < b) {

            vector<int> temp;

            // top row
            for (int i = l; i <= r; i++)
                temp.push_back(grid[t][i]);

            // right column
            for (int i = t + 1; i <= b - 1; i++)
                temp.push_back(grid[i][r]);

            // bottom row
            for (int i = r; i >= l; i--)
                temp.push_back(grid[b][i]);

            // left column
            for (int i = b - 1; i >= t + 1; i--)
                temp.push_back(grid[i][l]);

            rotatekpos(temp, k);

            spiral.push_back(temp);

            t++;
            l++;
            b--;
            r--;
        }

        // reset boundaries
        t = 0;
        l = 0;
        b = n - 1;
        r = m - 1;

        int layer = 0;

        // put back rotated layers
        while (l < r && t < b) {

            int idx = 0;

            // top row
            for (int i = l; i <= r; i++)
                grid[t][i] = spiral[layer][idx++];

            // right column
            for (int i = t + 1; i <= b - 1; i++)
                grid[i][r] = spiral[layer][idx++];

            // bottom row
            for (int i = r; i >= l; i--)
                grid[b][i] = spiral[layer][idx++];

            // left column
            for (int i = b - 1; i >= t + 1; i--)
                grid[i][l] = spiral[layer][idx++];

            layer++;

            t++;
            l++;
            b--;
            r--;
        }

        return grid;
    }
};