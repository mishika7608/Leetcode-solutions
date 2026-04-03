class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    //     int n =points.size();
    //     sort(points.begin(), points.end(), [](vector<int> 
    //     &a, vector<int> &b){if (a[0]==b[0]){return a[1]<b[1];}
    //     return a[0]<b[0];});
    //     int c=1;int e=points[0][1];
    //     for (int i=0;i<n;i++){
    //         if (points[i][0]>e){
    //             c++;
    //             e=points[i][1];
    //         }
    //     }
    //     return c;
    // }
    sort(points.begin(), points.end(), [](auto &a, auto &b){
        return a[1] < b[1];
    });

    int arrows = 1;
    int end = points[0][1];

    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > end) {
            arrows++;
            end = points[i][1];
        }
    }return arrows;
    }
};