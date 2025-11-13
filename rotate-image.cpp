class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        for (int i=0;i<n;i++){
            for (int j=0;j<=i;j++){
                int t=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=t;
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n/2;j++){
                int t=matrix[i][j];
                matrix[i][j]=matrix[i][n-j-1];
                matrix[i][n-j-1]=t;
            }
        }
        /*int l=0,r=n-1,t=0,b=n-1;
        while (l<r){
            int i=l;
            while (i<r){
                int temp=matrix[t+i][l];
                matrix[t+i][l]=matrix[b][l+i];
                matrix[b][l+i]=matrix[b-i][r];
                matrix[b-i][r]=matrix[t][r-i];
                matrix[t][r-i]=temp;
                i++;
            }
            l++;r--;
            t++;b--;
        }*/
        

    }
};
