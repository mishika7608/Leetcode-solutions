class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        
        long long ans = LLONG_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Land -> Water
                long long landFinish =
                    (long long)landStartTime[i] + landDuration[i];

                long long finish1 =
                    max(landFinish, (long long)waterStartTime[j]) +
                    waterDuration[j];

                // Water -> Land
                long long waterFinish =
                    (long long)waterStartTime[j] + waterDuration[j];

                long long finish2 =
                    max(waterFinish, (long long)landStartTime[i]) +
                    landDuration[i];

                ans = min(ans, min(finish1, finish2));
            }
        }

        return (int)ans;
    }
};