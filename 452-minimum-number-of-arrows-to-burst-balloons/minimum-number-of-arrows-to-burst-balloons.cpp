class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int> &a,const vector<int> &b){return a[0]<b[0];});
        int start=points[0][0],end=points[0][1];
        int n = points.size();
        int arrow=1;
        for (int i=1;i<n;i++){
            int val1=points[i][0],val2=points[i][1];
            if (val1<=end){
                end=min(end,val2);
            }
            else{
                arrow++;
                start=points[i][0];
                end=points[i][1];
            }
        }return arrow;
    }
};