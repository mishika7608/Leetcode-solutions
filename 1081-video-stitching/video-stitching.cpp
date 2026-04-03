class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int end = 0, far = 0, res = 0, i = 0, n = clips.size();
        while (end < time) {
            // expand coverage
            while (i < n && clips[i][0] <= end) {
                far = max(far, clips[i][1]);
                i++;
            }
            if (far == end) return -1; // cannot extend
            res++;
            end = far;
        }
        return res;
    }
};