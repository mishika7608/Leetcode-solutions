class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> height(n, 0);
        int maxArea = 0;
        
        for (int i = 0; i < m; i++) {
            // Build heights
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1)
                    height[j] += 1;
                else
                    height[j] = 0;
            }
            
            // Copy and sort in descending order
            vector<int> temp = height;
            sort(temp.begin(), temp.end(), greater<int>());
            
            // Calculate max area
            for (int j = 0; j < n; j++) {
                int area = temp[j] * (j + 1);
                maxArea = max(maxArea, area);
            }
        }
        
        return maxArea;
    }
};