class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row=0;
        int mx=0;
        vector<int> ans;
        for (int i=0;i<mat.size();i++){
            int count=0;
            for (int j=0;j<mat[i].size();j++){
                if (mat[i][j]==1){count++;}
            }
            if (mx<count){row=i;mx=count;}
        }
        ans.push_back(row);
        ans.push_back(mx);
        return ans;
    }
};
