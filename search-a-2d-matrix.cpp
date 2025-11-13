class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int j=0;
        if (target < matrix[j][0] || target > matrix[n-1][m-1]){
            return false;
        }
        while (j<n){
            if (target>=matrix[j][0] && target<=matrix[j][m-1]){
                 if (target==matrix[j][0] || target==matrix[j][m-1]){
                    return true;}
                break;
            }
            j++;
        }
        int f=0;
        if (j!=n){
            for (int i=0;i<matrix[j].size();i++){
                if (target==matrix[j][i]){
                    f=1;
                }
            }
        }
        return f?true:false;
    }
};
