class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int neg=0;
        long long AbsSum=0;
        int minAbs=INT_MAX;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (matrix[i][j]<0){neg++;}
                AbsSum+=abs(matrix[i][j]);
                minAbs=min(minAbs, abs(matrix[i][j]));
            }
        }
        return neg%2==0?AbsSum:AbsSum-2*minAbs;
    }
};