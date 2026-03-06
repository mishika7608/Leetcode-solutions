class Solution {
public:
    bool constraints(vector<string> &board, int row, int col){
        for (int i=0;i<board.size();i++){
            if (board[i][col]=='Q')return false;
            if (board[row][i]=='Q')return false;
        }
        for (int i=row,j=col;i>=0 && j>=0;i--,j--){
            if (board[i][j]=='Q')return false;
        }
        for (int i=row,j=col;i>=0 && j<board.size();i--,j++){
            if (board[i][j]=='Q')return false;
        }
        return true;
    }
    void helper(vector<string> &board, int row, vector<vector<string>> &ans){
        if (row==board.size()){
            ans.push_back(board);
            return ;
        }
        for (int i=0;i<board.size();i++){
            if (constraints(board,row,i)==true){
                board[row][i]='Q';
                helper(board, row+1,ans);
                board[row][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        for (int i=0;i<n;i++){
            string curr;
            for (int j=0;j<n;j++){
                curr+='.';
            }
            board.push_back(curr);
        }
        helper(board,0,ans);
        return ans.size();
    }

};