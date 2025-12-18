class Solution {
public:
    int CalcHistoArea(vector<int> &heights){
        heights.push_back(0);
        int n=heights.size();
        int maxArea=0;
        stack<int> st;
        for (int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int h = heights[st.top()];
                st.pop();
                int w = st.empty()?i : i-st.top()-1;
                maxArea = max(maxArea, h*w);
            }
            st.push(i);
        }
        heights.pop_back();
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n= matrix[0].size();
        vector<int> heights(n, 0);
        int ans = 0;

        for (auto &row : matrix){
            for (int j=0;j<n;j++){
                if (row[j]=='1'){heights[j]+=1;}
                else{heights[j]=0;}
            }
            ans=max(ans,CalcHistoArea(heights));
        }
        return ans;
    }
};