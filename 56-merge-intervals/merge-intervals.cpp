class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            if (a[0]!=b[0]){return a[0]<b[0];}
            return a[1]<b[1];
        });
        vector<vector<int>> ans;
        int s=intervals[0][0];
        int e=intervals[0][1];
        for (int i=1;i<intervals.size();i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if (e>=start){
                s=min(s,start);
                e=max(e,end);
            }else{
                ans.push_back({s,e});
                s=start;
                e=end;
            }
        }ans.push_back({s,e});
        return ans;
    }
};