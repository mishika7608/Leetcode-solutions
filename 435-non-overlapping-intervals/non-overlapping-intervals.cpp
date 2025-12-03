class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int c=0;
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end(),
        [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        int e=intervals[0][1];
        for (int i=1;i<n;i++){
            if (intervals[i][0] < e){c++;}
            else{
                e=max(e,intervals[i][1]);}
        }
        return c;
    }
};